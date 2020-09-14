//// chứa các thông tin authen khi đăng nhập xong
//})(angular.module('tedushop.common'));

//chứa thông thin authentication sau khi đăng nhập xong
// single page nên server và client tách biệt, nên client tạo athData để lưu thông tin đăng nhập của client
(function (app) {
    'use strict';
    app.factory('authData', [function () {
        var authDataFactory = {};
        var authentication = {
            IsAuthenticated: false,// chưa đăng nhập
            userName: "",
            accessToken: "",
            nameSpace: ""
        };
        authDataFactory.authenticationData = authentication;
        return authDataFactory;
    }]);
})(angular.module('dispatch.common'));
