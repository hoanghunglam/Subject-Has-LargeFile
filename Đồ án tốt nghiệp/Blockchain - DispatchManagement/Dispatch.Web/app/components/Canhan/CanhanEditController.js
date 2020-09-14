/// <reference path="../../../assets/admin/libs/angular/angular.js" />

(function (app) {
    app.controller('CanhanEditController', CanhanEditController);

    CanhanEditController.$inject = ['$scope', 'notificationService', 'apiService', '$state', '$stateParams', 'authData']

    function CanhanEditController($scope, notificationService, apiService, $state, $stateParams, authData) {

        $scope.participant = {
            $class: '',
            donVi: '',
            khoa: '',
            hoTen: '',
            matKhau: '',
            ngaySinh: '',
            gioiTinh: '',
            diaChi: ' ',
            email: '',
        }

        function LoadParticipantDetail() {
            apiService.getBlock('http://' + hostLam + ':3000/api/org.dispatch.CaNhan/' + $stateParams.id, {
                headers: {
                    'X-Access-Token': access_tokens
                }
            }, function (result) {
                $scope.participant.$class = result.data.$class;
                $scope.participantId = result.data.participantId;
                $scope.participant.donVi = result.data.donVi;
                $scope.participant.khoa = result.data.khoa;
                $scope.participant.hoTen = result.data.hoTen;
                $scope.participant.matKhau = result.data.matKhau;
                $scope.participant.ngaySinh = result.data.ngaySinh;
                $scope.participant.gioiTinh = result.data.gioiTinh;
                $scope.participant.diaChi = result.data.diaChi;
                $scope.participant.email = result.data.email;
                var ngaySinh = $scope.participant.ngaySinh.split("T");
                $scope.participant.ngaySinh = ngaySinh[0];
                console.log(result);
            }, function (error) {
                console.log(error);
                notificationService.displayError(error.data);
            });
        }
        LoadParticipantDetail();

        function UpdateParticipant() {
            apiService.putBlock('http://' + hostLam + ':3000/api/org.dispatch.CaNhan/' + $scope.participantId,
                $scope.participant, {
                    headers: {
                        'X-Access-Token': access_tokens
                    }
                }, function () {
                    notificationService.displaySuccess('Cập nhật thành công!');
                    $state.go('Canhan');
                },
                function (error) {
                    console.log(error);
                    notificationService.displayError('Cập nhật thất bại!');
                });
        }
        $scope.UpdateParticipant = UpdateParticipant;

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


})(angular.module('participant.Canhan'));