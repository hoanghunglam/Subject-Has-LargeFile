(function (app) {
    app.controller('loginController', loginController);
    loginController.$inject = ['localStorageService', '$scope', 'loginService', '$injector', 'notificationService', 'apiService', 'authData']
    function loginController(localStorageService, $scope, loginService, $injector, notificationService, apiService, authData) {
        $scope.loginData = {
            userId: "",
            password: "",
            role: "Admin"
        };
        $scope.loginSubmit = function () {
            $scope.loading = true;
            loginService.loginNetwork($scope.loginData.userId, $scope.loginData.password, $scope.loginData.role).then(
                function (response) {
                    if (response.status == '400' || response.status == '404' || response.status == '500') {
                        notificationService.displayError('Server not response!');
                        $scope.loading = false;
                    }
                    else {
                        setDefault();
                    }
                },
                function (error) {
                    console.log(error);
                    $scope.loading = false;
                    if (error.status == '404') {
                        notificationService.displayError('Server not response!');
                    } else {
                        notificationService.displayError('userName or password not correct!');
                    }
                });
        }
        function setDefault() {
            var url = 'http://' + hostLam + ':3000/api/wallet/' + $scope.loginData.userId + '@dispatch-management/setDefault';
            apiService.postBlock(url, null, {
                headers: {
                    'X-Access-Token': access_tokens
                }
            }, function (res) {
                console.log(res);
                pingCard();
            }, function (err) {
                console.log(err);
                $scope.loading = false;
                notificationService.displayError(err.data.error.message);
            });
        }
        function pingCard() {
            var url = 'http://' + hostLam + ':3000/api/system/ping';
            apiService.getBlock(url, {
                headers: {
                    'X-Access-Token': access_tokens
                }
            },
                function (response) {
                    //var accessTokenObj = JSON.parse(localStorage.getItem("nameSpace:"));
                    //console.log(accessTokenObj);
                    switch ($scope.loginData.role) {
                        case ('Admin'): {
                            var user = 'org.hyperledger.composer.system.NetworkAdmin#admin';
                            if (user == response.data.participant) {
                                // đúng nội dung thì login , không thì import card
                                notificationService.displaySuccess('login network success!');
                                var stateService = $injector.get('$state');
                                $scope.loading = false;
                                stateService.go('home');
                            } else {
                                // import card
                                notificationService.displayError('You need import card!');
                                $scope.loading = false;

                            }
                            break;
                        }
                        case ('LanhDaoCoQuan'): {
                            var user = 'org.dispatch.LanhDaoCoQuan#' + $scope.loginData.userId
                            if (user == response.data.participant) {
                                // đúng nội dung thì login , không thì import card
                                notificationService.displaySuccess('login network success!');
                                var stateService = $injector.get('$state');
                                $scope.loading = false;
                                stateService.go('home');
                            } else {
                                // import card
                                notificationService.displayError('You need import card!');
                                $scope.loading = false;

                            }
                            break;
                        }
                        case ('VanThuCuaBo'): {
                            var user = 'org.dispatch.VanThuCuaBo#' + $scope.loginData.userId
                            if (user == response.data.participant) {
                                // đúng nội dung thì login , không thì import card
                                notificationService.displaySuccess('login network success!');
                                var stateService = $injector.get('$state');
                                $scope.loading = false;
                                stateService.go('home');

                            } else {
                                // import card
                                notificationService.displayError('You need import card!');
                                $scope.loading = false;

                            }
                            break;

                        }
                        case ('LanhDaoDV'): {
                            var user = 'org.dispatch.LanhDaoDV#' + $scope.loginData.userId
                            if (user == response.data.participant) {
                                // đúng nội dung thì login , không thì import card
                                notificationService.displaySuccess('login network success!');
                                var stateService = $injector.get('$state');
                                $scope.loading = false;
                                stateService.go('home');
                            } else {
                                // import card
                                notificationService.displayError('You need import card!');
                                $scope.loading = false;

                            }
                            break;
                        }
                        case ('VanThuCuaDV'): {
                            var user = 'org.dispatch.VanThuCuaDV#' + $scope.loginData.userId
                            if (user == response.data.participant) {
                                // đúng nội dung thì login , không thì import card
                                notificationService.displaySuccess('login network success!');
                                var stateService = $injector.get('$state');
                                $scope.loading = false;
                                stateService.go('home');

                            } else {
                                // import card
                                notificationService.displayError('You need import card!');
                                $scope.loading = false;

                            }
                            break;
                        }
                        case ('CaNhan'): {
                            var user = 'org.dispatch.CaNhan#' + $scope.loginData.userId
                            if (user == response.data.participant) {
                                // đúng nội dung thì login , không thì import card
                                notificationService.displaySuccess('login network success!');
                                var stateService = $injector.get('$state');
                                $scope.loading = false;
                                stateService.go('home');

                            } else {
                                // import card
                                notificationService.displayError('You need import card!');
                                $scope.loading = false;

                            }
                            break;
                        }
                    }
                    console.log(response);
                },
                function (err) {
                    console.log(err);
                    $scope.loading = false;
                    notificationService.displayError(err.data.error.message);
                });
        }

        //function permissionLayoutUser() {
        //    var tokenInfo = localStorageService.get("TokenInfo");
        //    tokenInfo = JSON.parse(tokenInfo);
        //    if (tokenInfo != null) {
        //        switch (tokenInfo.nameSpace) {
        //            case ('userUnit'): {
        //                hideuser();
        //                break;
        //            }
        //            case ('userUnit'): {
        //                hideuser();
        //                break;
        //            }
        //            case ('User'): {
        //                hideUser();
        //                break;
        //            }
        //        }
        //    }
        //}
        //function hideuser() {
        //    $('#info-dispatch').remove();
        //    $('#send-dispatch').remove();
        //}
        //function hideUser() {
        //    $('#dispatch').remove();
        //    $('#approvel-dispatch').remove();
        //    $('#user-dispatch').remove();
        //    $('#send-dispatch').remove();
        //}
        //function hideuser() {
        //    $('#user-dispatch').remove();
        //    $('#info-dispatch').remove();
        //    $('#approvel-dispatch').remove();
        //}
        //permissionLayoutUser();

    }
})(angular.module('dispatch'));


