/// <reference path="../../../assets/admin/libs/ngbootbox/ngbootbox.js" />

(function (app) {
    app.controller('LanhdaocoquanListController', LanhdaocoquanListController);
    LanhdaocoquanListController.$inject = ['$scope', 'apiService', 'notificationService', '$ngBootbox', 'authData'];

    function LanhdaocoquanListController($scope, apiService, notificationService, $ngBootbox, authData) {
        $scope.getParticipant;
        $scope.getParticipantList = getParticipantList;
        $scope.keyword = '';
        $scope.deleteParticipant = deleteParticipant;
        $scope.searchParticipant = searchParticipant;

        function getParticipantList() {
            apiService.getBlock('http://' + hostLam + ':3000/api/queries/AllLanhDaoCoQuan', {
                headers: {
                    'X-Access-Token': access_tokens
                }
            },
                function (result) {
                    if (result.data.TotaCount == 0) {
                        notificationService.displayWarning('Không có dữ liệu!');
                    }
                    $scope.getParticipant = result.data;
                    console.log($scope.getParticipant);
                    for (var i = 0; i < $scope.getParticipant.length; i++) {
                        var ngaySinh = $scope.getParticipant[i].ngaySinh.split("T");
                        $scope.getParticipant[i].ngaySinh = ngaySinh[0];
                        switch ($scope.getParticipant[i].bo) {
                            case "Bo_GD":
                                $scope.getParticipant[i].bo = "Bộ giáo dục";
                                break;
                            case "Bo_QP":
                                $scope.getParticipant[i].bo = "Bộ quốc phòng";
                                break;
                            case "Bo_GTVT":
                                $scope.getParticipant[i].bo = "Bộ giao thông vận tải";
                                break;
                            case "Bo_NN":
                                $scope.getParticipant[i].bo = "Bộ nông nghiệp";
                                break;
                            case "Bo_CT":
                                $scope.getParticipant[i].bo = "Bộ chính trị";
                                break;
                            case "Bo_TC":
                                $scope.getParticipant[i].bo = "Bộ tài chính";
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

        function LoadParticipantDetail(ID) {
            apiService.getBlock('http://' + hostLam + ':3000/api/org.dispatch.LanhDaoCoQuan/' + ID, {
                headers: {
                    'X-Access-Token': access_tokens
                }
            }, function (result) {
                $scope.getParticipant = result.data;
                var ngaySinh = $scope.getParticipant.ngaySinh.split("T");
                $scope.getParticipant.ngaySinh = ngaySinh[0];
                switch ($scope.getParticipant.bo) {
                    case "Bo_GD":
                        $scope.getParticipant.bo = "Bộ giáo dục";
                        break;
                    case "Bo_QP":
                        $scope.getParticipant.bo = "Bộ quốc phòng";
                        break;
                    case "Bo_GTVT":
                        $scope.getParticipant.bo = "Bộ giao thông vận tải";
                        break;
                    case "Bo_NN":
                        $scope.getParticipant.bo = "Bộ nông nghiệp";
                        break;
                    case "Bo_CT":
                        $scope.getParticipant.bo = "Bộ chính trị";
                        break;
                    case "Bo_TC":
                        $scope.getParticipant.bo = "Bộ tài chính";
                        break;
                }
                switch ($scope.getParticipant.gioiTinh) {
                    case "Nam":
                        $scope.getParticipant.gioiTinh = "Nam";
                        break;
                    case "Nu":
                        $scope.getParticipant.gioiTinh = "Nữ";
                        break;
                    case "Khac":
                        $scope.getParticipant.gioiTinh = "Khác";
                        break;
                }
                console.log(result);
            }, function (error) {
                console.log(error);
                notificationService.displayError(error.data);
            });
        }

        function searchParticipant() {
            if ($scope.keyword == '') {
                $scope.getParticipantList();
            }
            else {
            }
        }

        function deleteParticipant(ID) {
            $ngBootbox.confirm("Bạn chắc chắn muốn xóa!").then(function () {
                apiService.delBlock('http://' + hostLam + ':3000/api/org.dispatch.LanhDaoCoQuan/' + ID,
                    {
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
})(angular.module('participant.Lanhdaocoquan'));