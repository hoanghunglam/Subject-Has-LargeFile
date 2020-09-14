/// <reference path="../../../assets/admin/libs/ngbootbox/ngbootbox.js" />

(function (app) {
    app.controller('historyTransactionListController', historyTransactionListController);
    historyTransactionListController.$inject = ['$scope', 'apiService', 'notificationService', 'authData'];

    function historyTransactionListController($scope, apiService, notificationService, authData) {
        $scope.GuiCongVanDen;
        $scope.GuiCongVanDi;
        $scope.NhanCongVanDi;
        $scope.getTransaction;
        $scope.getTransactionList = getTransactionList;
        $scope.keyword = '';
        $scope.searchParticipant = searchParticipant;

        function getTransactionList() {
            apiService.getBlock('http://' + hostLam + ':3000/api/org.dispatch.GuiCongVanDen', {
                headers: {
                    'X-Access-Token': access_tokens
                }
            },
                function (result) {
                    if (result.data.TotaCount == 0) {
                        notificationService.displayWarning('Không có dữ liệu!');
                    }
                    $scope.GuiCongVanDen = result.data;
                    console.log($scope.GuiCongVanDen);
                    for (var i = 0; i < $scope.GuiCongVanDen.length; i++) {
                        var date = $scope.GuiCongVanDen[i].timestamp.split("T");
                        var time = date[1].split(".");
                        $scope.GuiCongVanDen[i].timestamp = date[0] + ', ' + time[0];
                        var dispatch = $scope.GuiCongVanDen[i].congVan.split("#");
                        $scope.GuiCongVanDen[i].congVan = dispatch[1];
                        var type = $scope.GuiCongVanDen[i].$class.split(".");
                        $scope.GuiCongVanDen[i].$class = type[type.length - 1];
                        var user = $scope.GuiCongVanDen[i].nguoiGui.split("#");
                        $scope.GuiCongVanDen[i].nguoiGui = user[1];
                   }
                }, function (error) {
                        notificationService.displayError('Tải dữ liệu không thành công!');
                        console.log(error.data + 'Load data failed!');
                });
            apiService.getBlock('http://' + hostLam + ':3000/api/org.dispatch.NhanCongVanDen', {
                headers: {
                    'X-Access-Token': access_tokens
                }
            },
                function (result) {
                    if (result.data.TotaCount == 0) {
                        notificationService.displayWarning('Không có dữ liệu!');
                    }
                    $scope.getTransaction = result.data;
                    for (var i = 0; i < $scope.getTransaction.length; i++) {
                        var date = $scope.getTransaction[i].timestamp.split("T");
                        var time = date[1].split(".");
                        $scope.getTransaction[i].timestamp = date[0] + ', ' + time[0];
                        var dispatch = $scope.getTransaction[i].congVan.split("#");
                        $scope.getTransaction[i].congVan = dispatch[1];
                        var type = $scope.getTransaction[i].$class.split(".");
                        $scope.getTransaction[i].$class = type[type.length - 1];
                        var user = $scope.getTransaction[i].nguoiDuyet.split("#");
                        $scope.getTransaction[i].nguoiDuyet = user[1];
                    }
                    console.log($scope.getTransaction);
                }, function (error) {
                    notificationService.displayError('Tải dữ liệu không thành công!');
                    console.log(error.data + 'Load data failed!');
                });
                apiService.getBlock('http://' + hostLam + ':3000/api/org.dispatch.GuiCongVanDi', {
                            headers: {
                                'X-Access-Token': access_tokens
                            }
                        },
                            function (result) {
                                if (result.data.TotaCount == 0) {
                                    notificationService.displayWarning('Không có dữ liệu!');
                                }
                                $scope.GuiCongVanDi = result.data;
                                console.log($scope.GuiCongVanDi);
                                for (var i = 0; i < $scope.GuiCongVanDi.length; i++) {
                                    var date = $scope.GuiCongVanDi[i].timestamp.split("T");
                                    var time = date[1].split(".");
                                    $scope.GuiCongVanDi[i].timestamp = date[0] + ', ' + time[0];
                                    var dispatch = $scope.GuiCongVanDi[i].congVan.split("#");
                                    $scope.GuiCongVanDi[i].congVan = dispatch[1];
                                    var type = $scope.GuiCongVanDi[i].$class.split(".");
                                    $scope.GuiCongVanDi[i].$class = type[type.length - 1];
                                    var user = $scope.GuiCongVanDi[i].nguoiGui.split("#");
                                    $scope.GuiCongVanDi[i].nguoiGui = user[1];
                                }
                            }, function (error) {
                                    notificationService.displayError('Tải dữ liệu không thành công!');
                                    console.log(error.data + 'Load data failed!');
                            });
                apiService.getBlock('http://' + hostLam + ':3000/api/org.dispatch.NhanCongVanDenDi', {
                            headers: {
                                'X-Access-Token': access_tokens
                            }
                        },
                            function (result) {
                                if (result.data.TotaCount == 0) {
                                    notificationService.displayWarning('Không có dữ liệu!');
                                }
                                $scope.NhanCongVanDi = result.data;
                                console.log($scope.NhanCongVanDi);
                                for (var i = 0; i < $scope.NhanCongVanDi.length; i++) {
                                    var date = $scope.NhanCongVanDi[i].timestamp.split("T");
                                    var time = date[1].split(".");
                                    $scope.NhanCongVanDi[i].timestamp = date[0] + ', ' + time[0];
                                    var dispatch = $scope.NhanCongVanDi[i].congVan.split("#");
                                    $scope.NhanCongVanDi[i].congVan = dispatch[1];
                                    var type = $scope.NhanCongVanDi[i].$class.split(".");
                                    $scope.NhanCongVanDi[i].$class = type[type.length - 1];
                                    var user = $scope.NhanCongVanDi[i].nguoiDuyet.split("#");
                                    $scope.NhanCongVanDi[i].nguoiDuyet = user[1];
                                }
                            }, function (error) {
                                    notificationService.displayError('Tải dữ liệu không thành công!');
                                    console.log(error.data + 'Load data failed!');
                            });
        }
        $scope.getTransactionList();

        function searchParticipant() {
            if ($scope.keyword == '') {
                $scope.getTransactionList();
            }
            else {
            }
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
})(angular.module('dispatch.history'));