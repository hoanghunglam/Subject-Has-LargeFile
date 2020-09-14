/// <reference path="../../../assets/admin/libs/ngbootbox/ngbootbox.js" />

(function (app) {
    app.controller('historySystemListController', historySystemListController);
    historySystemListController.$inject = ['$scope', 'apiService', 'notificationService', 'authData'];

    function historySystemListController($scope, apiService, notificationService, authData) {
        $scope.getTransaction;
        $scope.getTransactionList = getTransactionList;
        $scope.keyword = '';
        $scope.searchParticipant = searchParticipant;

        function getTransactionList() {
            apiService.getBlock('http://' + hostLam + ':3000/api/system/historian', {
                headers: {
                    'X-Access-Token': access_tokens
                }
            }, function (result) {
                if (result.data.TotaCount == 0) {
                    notificationService.displayWarning('Không có dữ liệu!');
                }
                $scope.getTransaction = result.data;
                console.log($scope.getTransaction);
                for (var i = 0; i < $scope.getTransaction.length; i++) {
                    var date = $scope.getTransaction[i].transactionTimestamp.split("T");
                    var time = date[1].split(".");
                    $scope.getTransaction[i].transactionTimestamp = date[0] + ', ' + time[0];
                    var type = $scope.getTransaction[i].transactionType.split(".");
                    $scope.getTransaction[i].transactionType = type[type.length-1];
                    if($scope.getTransaction[i].participantInvoking == null){
                        $scope.getTransaction[i].participantInvoking = "";
                    }
                    else{
                        var user = $scope.getTransaction[i].participantInvoking.split("#");
                        var role = user[0].split(".");
                        $scope.getTransaction[i].participantInvoking = user[1] + ' (' + role[2] + ')';
                    }
                    console.log(result);
                    console.log(result.data);
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
                //$scope.getTransaction() = $scope.getTransaction();
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