(function (app) {
    'use strict';
    app.service('loginService', ['$q', 'authenticationService', 'authData', 'apiService',
        function ($q, authenticationService, authData, apiService) {
            let userInfo;
            let deferred;
            this.loginNetwork = function (userId, password, role) {
                deferred = $q.defer();
                var param = '';
                if (role == "Admin") {
                    if (userId == "lam" && password == "1") {
                        var data = 'http://' + hostLam + ':3000/api/system/ping';
                        apiService.getBlock(data, {
                            headers:
                                { 'X-Access-Token': access_tokens }
                        }, function (res) {
                            console.log(res);
                            // xu lý ping hệ thống xem user nào đang đăng nhập
                            userInfo = {
                                accessToken: access_tokens,
                                userName: userId,
                                nameSpace: role
                            };
                            authenticationService.setTokenInfo(userInfo);
                            authData.authenticationData.userName = userId;
                            authData.authenticationData.nameSpace = role;
                            deferred.resolve(res);
                        }, function (err) {
                            authData.authenticationData.IsAuthenticated = false;
                            authData.authenticationData.userName = '';
                            authData.authenticationData.nameSpace = '';
                            deferred.reject(err);
                        });
                    }
                }
                else {
                    switch (role) {
                        case ('LanhDaoCoQuan'): {
                            param = 'LanhDaoCoQuan';
                            break;
                        }
                        case ('VanThuCuaBo'): {
                            param = 'VanThuCuaBo';
                            break;
                        }
                        case ('LanhDaoDV'): {
                            param = 'LanhDaoDV';
                            break;
                        }
                        case ('VanThuCuaDV'): {
                            param = 'VanThuCuaDV';
                            break;
                        }
                        case ('CaNhan'): {
                            param = 'CaNhan';
                            break;
                        }
                    }
                    // lay ra thong tin user
                    var data = 'http://' + hostLam + ':3000/api/org.dispatch.' + param + '/' + userId;
                    apiService.getBlock(data, {
                        headers:
                            { 'X-Access-Token': access_tokens }
                    }, function (res) {
                        console.log(res);
                        // xu lý ping hệ thống xem user nào đang đăng nhập
                        if (res.data.matKhau == password) {
                            userInfo = {
                                accessToken: access_tokens,
                                userName: userId,
                                nameSpace: role
                            };
                            authenticationService.setTokenInfo(userInfo);
                            authData.authenticationData.userName = userId;
                            authData.authenticationData.nameSpace = role;
                            deferred.resolve(res);
                        }
                        else {
                            authData.authenticationData.IsAuthenticated = false;
                            authData.authenticationData.userName = '';
                            authData.authenticationData.nameSpace = '';
                            deferred.reject(res);
                        }
                    }, function (err) {
                        authData.authenticationData.IsAuthenticated = false;
                        authData.authenticationData.userName = '';
                        authData.authenticationData.nameSpace = '';
                        deferred.reject(err);
                        });
                }
                return deferred.promise;
            }
            this.logOut = function () {
                //apiService.post('/api/account/logout', null, function (response) {
                authenticationService.removeToken();
                authData.authenticationData.IsAuthenticated = false;
                authData.authenticationData.userName = '';
                authData.authenticationData.accessToken = '';
                authData.authenticationData.nameSpace = '';
                //}, null);
            }
        }]);
})(angular.module('dispatch.common'));