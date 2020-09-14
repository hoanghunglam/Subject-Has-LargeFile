
(function (app) {
    'use strict';
    app.controller('VanthuDVAddController', VanthuDVAddController);
    // $state đối tượng  của ui-router để điều hướng 
    VanthuDVAddController.$inject = ['$scope', 'apiService', 'notificationService', '$state', 'authData'];

    function VanthuDVAddController($scope, apiService, notificationService, $state, authData) {
        $scope.participant = {
            $class: 'org.dispatch.VanThuCuaDV',
            donVi: 'HV_KTQS',
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
            apiService.postBlock('http://' + hostLam + ':3000/api/org.dispatch.VanThuCuaDV', $scope.participant, {
                headers: {
                    'X-Access-Token': access_tokens
                }
            }, function () {
                notificationService.displaySuccess('Tạo mới thành công!');
                $state.go('VanthuDV');
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
})(angular.module('participant.VanthuDV'));


