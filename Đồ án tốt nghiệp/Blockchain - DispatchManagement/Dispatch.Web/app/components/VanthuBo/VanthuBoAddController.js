
(function (app) {
    'use strict';
    app.controller('VanthuBoAddController', VanthuBoAddController);
    // $state đối tượng  của ui-router để điều hướng 
    VanthuBoAddController.$inject = ['$scope', 'apiService', 'notificationService', '$state', 'authData'];

    function VanthuBoAddController($scope, apiService, notificationService, $state, authData) {
        $scope.participant = {
            $class: 'org.dispatch.VanThuCuaBo',
            bo: 'Bo_GD',
            participantId: '',
            hoTen: '',
            matKhau: '123456',
            ngaySinh: '',
            gioiTinh: '',
            diaChi: '',
            email: '',
        }
        $scope.AddParticipant = AddParticipant;

        function AddParticipant() {
            apiService.postBlock('http://' + hostLam + ':3000/api/org.dispatch.VanThuCuaBo', $scope.participant,{
                headers: {
                    'X-Access-Token': access_tokens
                }
            },function () {
                    notificationService.displaySuccess('Tạo mới thành công!');
                    $state.go('VanthuBo');
                }, function (error) {
                    console.log(error.data);
                    notificationService.displayError('Tạo mới thất bại!');
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
})(angular.module('participant.VanthuBo'));


