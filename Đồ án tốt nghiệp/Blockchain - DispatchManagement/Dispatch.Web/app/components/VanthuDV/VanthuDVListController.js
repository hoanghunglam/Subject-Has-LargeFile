
/// <reference path="../../../assets/admin/libs/ngdonViotdonVix/ngdonViotdonVix.js" />

(function (app) {
    app.controller('VanthuDVListController', VanthuDVListController);
    VanthuDVListController.$inject = ['$scope', 'apiService', 'notificationService', '$ngBootbox', 'authData'];

    function VanthuDVListController($scope, apiService, notificationService, $ngBootbox, authData) {
        ;
        $scope.getParticipant;
        $scope.getParticipantList = getParticipantList;
        $scope.keyword = '';
        $scope.deleteParticipant = deleteParticipant;
        $scope.searchParticipant = searchParticipant;

        function getParticipantList() {
            apiService.getBlock('http://' + hostLam + ':3000/api/queries/AllVanThuCuaDV', {
                headers: {
                    'X-Access-Token': access_tokens
                }
            }, function (result) {
                if (result.data.TotaCount == 0) {
                    notificationService.displayWarning('Không có dữ liệu!');
                }
                $scope.getParticipant = result.data;
                console.log($scope.getParticipant);
                for (var i = 0; i < $scope.getParticipant.length; i++) {
                    var ngaySinh = $scope.getParticipant[i].ngaySinh.split("T");
                    $scope.getParticipant[i].ngaySinh = ngaySinh[0];
                    switch ($scope.getParticipant[i].donVi) {
                        case "HV_KTQS":
                            $scope.getParticipant[i].donVi = "Học viện kỹ thuật quân sự";
                            break;
                        case "HV_KTMM":
                            $scope.getParticipant[i].donVi = "Học viện kỹ thuật mật mã";
                            break;
                        case "DH_QGHN":
                            $scope.getParticipant[i].donVi = "Đại học quốc gia hà nội";
                            break;
                        case "HV_TC":
                            $scope.getParticipant[i].donVi = "Học viện tài chính";
                            break;
                        case "HV_BCVT":
                            $scope.getParticipant[i].donVi = "Học viện bưu chính viễn thông";
                            break;
                    }
                    switch ($scope.getParticipant[i].gioiTinh) {
                        case "Nam":
                            $scope.getParticipant[i].gioiTinh = "Nam";
                            break;
                        case "Nu":
                            $scope.getParticipant[i].gioiTinh = "Nữ";
                            break;
                        case "Khac":
                            $scope.getParticipant[i].gioiTinh = "Khác";
                            break;
                    }
                }
                console.log(result);
                console.log(result.data);
            }, function (error) {
                notificationService.displayError('Tải dữ liệu không thành công!');
                console.log(error.data + 'Load data failed!');
            });
        }
        $scope.getParticipantList();

        function searchParticipant() { }

        function deleteParticipant(ID) {
            $ngBootbox.confirm("Bạn chắc chắn muốn xóa!").then(function () {
                apiService.delBlock('http://' + hostLam + ':3000/api/org.dispatch.VanThuCuaDV/' + ID, {
                    headers: {
                        'X-Access-Token': access_tokens
                    }
                }, function () {
                    notificationService.displaySuccess('Đã xóa thành công!');
                    $scope.getParticipantList();
                }, function (error) {
                    console.log(error);
                    notificationService.displayWarning('Xóa không thành công!');
                });
            });
        }

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
        }
        loginUserCard();
    }
})(angular.module('participant.VanthuDV'));