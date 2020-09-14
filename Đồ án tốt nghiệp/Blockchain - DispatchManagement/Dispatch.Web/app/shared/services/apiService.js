/// <reference path="../../../Assets/admin/libs/angular/angular.js" />
(function (app) {
    app.factory('apiService', apiService);

    apiService.$inject = ['$http', 'notificationService', 'authenticationService'];

    function apiService($http, notificationService, authenticationService) {
        // public phương thức bằng cách return 
        return {
            get: get,
            post: post,
            put: put,
            del: del,
            postBlock: postBlock,
            putBlock: putBlock,
            getBlock: getBlock,
            delBlock: delBlock
        }
        function post(url, data, success, failure) {
            authenticationService.setHeader();
            $http.post(url, data).then(
                function (result) {
                    success(result);
                }, function (error) {
                    if (error.status == '401') {
                        notificationService.displayError('Authenticate is requiered')
                    } else if (failure != null) {
                        failure(error);
                        notificationService.displayError('Lỗi')
                        notificationService.displayError(error)
                    }
                });
        }
        function del(url, data, success, failure) {
            authenticationService.setHeader();
            $http.delete(url, data).then(function (result) {
                success(result);
            }, function () {
                if (error.status == '401') {
                    notificationService.displayError('Authenticate is requiered')
                } else if (failure != null) {
                    failure(error);
                }
            });
        }
        function put(url, data, success, failure) {
            authenticationService.setHeader();
            $http.put(url, data).then(function (result) {
                success(result);
            }, function (error) {
                if (error.status == '401') {
                    notificationService.displayError('Authenticate is requiered')
                } else if (failure != null) {
                    failure(error);
                }
            });
        }
        function get(url, params, success, failure) {
            //authenticationService.setHeader();
            //console.log(params);
            $http.get(url, params).then(function (result) {
                success(result);
            }, function (error) {
                failure(error);
                console.log(error);
            });
        }



        //----------------------- api for network------------------//
        function postBlock(url, data, headers, success, failure) {
            $http.post(url, data, headers).then(
                function (result) {
                    success(result);
                }, function (err) {
                    console.log(err);
                    failure(err);
                });
        }
        function putBlock(url, data, headers, success, failure) {
            $http.put(url, data, headers).then(function (res) {
                console.log(res)
                success(res);
            }, function (err) {
                failure(err);
            });
        }

        function getBlock(url, headers, success, failure) {
            $http.get(url, headers).then(function (res) {
                console.log(res)
                success(res);
            }, function (err) {
                failure(err);
            });
        }

        function delBlock(url, headers, success, failure) {
            $http.delete(url, headers).then(
                function (result) {
                    success(result);
                }, function (err) {
                    failure(err)
                });
        }
    }
})(angular.module('dispatch.common')); // add namespace thuộc tedushop.common
