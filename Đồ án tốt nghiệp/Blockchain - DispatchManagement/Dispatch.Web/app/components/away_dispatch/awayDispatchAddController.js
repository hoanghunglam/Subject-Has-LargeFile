
(function (app) {
    'use strict';
    app.controller('awayDispatchAddController', awayDispatchAddController);
    // $state đối tượng  của ui-router để điều hướng 
    awayDispatchAddController.$inject = ['$scope', 'apiService', 'notificationService', '$state', 'authData'];

    function awayDispatchAddController($scope, apiService, notificationService, $state, authData) {
        $scope.dispatch = {
            $class: 'org.dispatch.CongVanDen',
            assetId: '',
            kieu: 'Chithi_CT',
            so: '',
            ngayPhatHanh: '',
            ngayTao: '',
            trichYeu: ' ',
            data: '',
            linhVuc: 'GDDT_GiaoducDaotao',
            tinhTrang: 'Dang_xu_ly',
            noiPhatHanh: 'Bo_GD',
            noiNhan: ["HV_KTQS"],
            nguoiKy: "",
            nguoiKyNhay: "",
            nguoiGui: " ",
            nguoiDuyet: " ",
        }
        $scope.sender = {
            $class: 'org.dispatch.GuiCongVanDen',
            congVan: '',
            nguoiGui: '',
        }
        var ngay = new Date().getDate();
        var thang = new Date().getMonth();
        thang++;
        var nam = new Date().getFullYear();
        if (thang < 10) {
            $scope.ngayMax = "" + nam + "-0" + thang + "-" + ngay;
        }
        else $scope.ngayMax = "" + nam + "-" + thang + "-" + ngay;
        console.log($scope.ngayMax);

        $scope.uploadFile = uploadFile;
        function uploadFile() {
            var input = document.getElementById('fileInput');
            console.log(input);
            var file = input.files[0];

            var fileReader = new FileReader();

            fileReader.readAsBinaryString(file);

            fileReader.onload = function () {

                var stringData = fileReader.result;

                const repoPath = 'ipfs-' + Math.random();
                const ipfs = new Ipfs({ repo: repoPath });

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

        function Adddispatch() {
            $scope.dispatch.nguoiKy = "org.dispatch.LanhDaoCoQuan#" + $scope.nguoiKy;
            $scope.dispatch.nguoiKyNhay = "org.dispatch.VanThuCuaBo#" + $scope.nguoiKyNhay;
            apiService.postBlock('http://' + hostLam + ':3000/api/org.dispatch.CongVanDen', $scope.dispatch, {
                headers: {
                    'X-Access-Token': access_tokens
                }
            }, function () {
                notificationService.displaySuccess('Tạo mới thành công!');
                $scope.sender.congVan = $scope.dispatch.assetId;
                    apiService.postBlock('http://' + hostLam + ':3000/api/org.dispatch.GuiCongVanDen', $scope.sender, {
                    headers: {
                        'X-Access-Token': access_tokens
                    }
                }, function (data) {
                    console.log(data);
                }
                    , function (error) {
                        console.log(error.data);
                    });
                $state.go('awayDispatch');
            }, function (error) {
                console.log(error.data);
                notificationService.displayError('Tạo mới thất bại!');
            });
        }
        $scope.Adddispatch = Adddispatch;

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


