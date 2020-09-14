/// <reference path="../../../assets/admin/libs/angular/angular.js" />

(function (app) {
    app.controller('awayDispatchEditController', awayDispatchEditController);

    awayDispatchEditController.$inject = ['$scope', 'notificationService', 'apiService', '$state', '$stateParams', 'authData']

    function awayDispatchEditController($scope, notificationService, apiService, $state, $stateParams, authData) {

        // khai báo các đối tượng binding sang view sử dụng scope
        $scope.dispatch = {
            $class: '',
            kieu: '',
            so: '',
            ngayPhatHanh: '',
            ngayTao: '',
            trichYeu: '',
            data: '',
            linhVuc: '',
            tinhTrang: '',
            noiPhatHanh: '',
            noiNhan: [],
            nguoiKy: '',
            nguoiKyNhay: '',
            nguoiGui: '',
            nguoiDuyet: '',
        }
        $scope.sender = {
            $class: 'org.dispatch.GuiCongVanDen',
            congVan: '',
            nguoiGui: '',
        }
        function loadDispatchDetail() {
            apiService.getBlock('http://' + hostLam + ':3000/api/org.dispatch.CongVanDen/' + $stateParams.id, {
                headers: {
                    'X-Access-Token': access_tokens
                }
            }, function (result) {
                $scope.dispatch.$class = result.data.$class;
                $scope.dispatchId = result.data.assetId;
                $scope.dispatch.kieu = result.data.kieu;
                $scope.dispatch.so = result.data.so;
                $scope.dispatch.ngayPhatHanh = result.data.ngayPhatHanh;
                $scope.dispatch.ngayTao = result.data.ngayTao;
                $scope.dispatch.trichYeu = result.data.trichYeu;
                $scope.dispatch.data = result.data.data;
                $scope.dispatch.linhVuc = result.data.linhVuc;
                $scope.dispatch.tinhTrang = result.data.tinhTrang;
                $scope.dispatch.noiPhatHanh = result.data.noiPhatHanh;
                $scope.dispatch.noiNhan = result.data.noiNhan;
                var nguoiKy = result.data.nguoiKy.split("#");
                $scope.nguoiKy = nguoiKy[1];
                var nguoiKyNhay = result.data.nguoiKyNhay.split("#");
                $scope.nguoiKyNhay = nguoiKyNhay[1];
                $scope.dispatch.nguoiGui = result.data.nguoiGui;
                $scope.dispatch.nguoiDuyet = result.data.nguoiDuyet;
                var ngayPhatHanh = $scope.dispatch.ngayPhatHanh.split("T");
                $scope.dispatch.ngayPhatHanh = ngayPhatHanh[0];
                var ngayTao = $scope.dispatch.ngayTao.split("T");
                $scope.dispatch.ngayTao = ngayTao[0];
                console.log(result);
            }, function (error) {
                console.log(error);
                notificationService.displayError(error.data);
            });
        }
        loadDispatchDetail();

        var ngay = new Date().getDate();
        var thang = new Date().getMonth();
        thang++;
        var nam = new Date().getFullYear();
        if (thang < 10) {
            $scope.ngayMax = "" + nam + "-0" + thang + "-" + ngay;
        }
        else $scope.ngayMax = "" + nam + "-" + thang + "-" + ngay;

        $scope.uploadFile = uploadFile;
        //uploadFile();
        function uploadFile() {
            var input = document.getElementById('fileInput');
            console.log(input);
            var file = input.files[0];

            var fileReader = new FileReader();

            fileReader.readAsBinaryString(file);

            fileReader.onload = function () {
                //appendLog("onload!");

                var stringData = fileReader.result;
                //appendLog(stringData);

                const repoPath = 'ipfs-' + Math.random();
                const ipfs = new Ipfs({ repo: repoPath });
                //const ipfs = new Ipfs({ host: 'ipfs.infura.io', port: 5001, protocol: 'https' });

                ipfs.on('ready', () => {
                    const Buffer = window.Ipfs.Buffer
                    console.log(Buffer.from(btoa(fileReader.result), "base64"));
                    const files = [
                        {
                            path: 'image1.png',
                            content: Buffer.from(btoa(fileReader.result), "base64")
                        }
                    ]
                    ipfs.add(files, function (err, files) {
                        let url = "https://ipfs.io/ipfs/" + files[0].hash;
                        console.log(url);
                        $scope.dispatch.data = files[0].hash;
                        log("Storing file on IPFS using Javascript. HASH: https://ipfs.io/ipfs/" + files[0].hash);
                        var ipfsPath = files[0].hash
                        ipfs.cat(ipfsPath, function (err, result) {
                            if (err) {
                                throw err
                            }
                            var img = file.toString("base64");
                            document.getElementById("dataEncode").src = "data:image/png;base64," + img;
                        });
                    });

                    const log = (line) => {
                        document.getElementById('dataEncode').appendChild(document.createTextNode(`${line}\r\n`))
                    }

                });
            }

        }
        function Updatedispatch() {
            $scope.dispatch.nguoiKy = "org.dispatch.LanhDaoCoQuan#" + $scope.nguoiKy;
            $scope.dispatch.nguoiKyNhay = "org.dispatch.VanThuCuaBo#" + $scope.nguoiKyNhay;
            $scope.sender.congVan = $scope.dispatchId;
            apiService.postBlock('http://' + hostLam + ':3000/api/org.dispatch.GuiCongVanDen', $scope.sender, {
                headers: {
                    'X-Access-Token': access_tokens
                }
            }, function (result) {
                $scope.dispatch.nguoiGui = result.data.nguoiGui;
                apiService.putBlock('http://' + hostLam + ':3000/api/org.dispatch.CongVanDen/' + $scope.dispatchId,
                    $scope.dispatch, {
                        headers: {
                            'X-Access-Token': access_tokens
                        }
                    }, function (data) {
                        notificationService.displaySuccess('Cập nhật thành công!');
                        console.log(data);
                    }
                    , function (error) {
                        notificationService.displayError('Cập nhật thất bại!');
                        console.log(error.data);
                    });
                $state.go('awayDispatch');
                }, function (error) {
                    notificationService.displayError('Cập nhật thất bại!');
                    console.log(error);
            });
        }
        $scope.Updatedispatch = Updatedispatch;

        function loginUserCard() {
            $scope.loading = true;
            var url = 'http://' + hostLam + ':3000/api/wallet/' + authData.authenticationData.userName + '@dispatch-management/setDefault';
            apiService.postBlock(url, null,
                {
                    headers: {
                        'X-Access-Token': access_tokens
                    }
                },
                function (res) {

                    console.log(res);
                }, function (err) {
                    console.log(err);
                    notificationService.displayError(err.data.error.message);
                    $scope.loading = false;
                });
            apiService.getBlock('http://' + hostLam + ':3000/api/system/ping', {
                headers:
                    { 'X-Access-Token': access_tokens }
            }, function (result) {
                $scope.sender.nguoiGui = result.data.participant;
                console.log($scope.sender.nguoiGui);
            }, function (er) {
                console.log(er);
            });
        }
        loginUserCard();
    }
})(angular.module('dispatch.awayDispatch'));