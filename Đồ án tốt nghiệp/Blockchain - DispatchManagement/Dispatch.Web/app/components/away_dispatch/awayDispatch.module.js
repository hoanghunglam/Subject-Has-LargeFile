/// <reference path="../../../Assets/admin/libs/angular/angular.js" />

(function () {
    angular.module('dispatch.awayDispatch', ['dispatch.common']).config(config);
    config.$inject = ['$stateProvider', '$urlRouterProvider'];

    function config($stateProvider, $urlRouterProvider) {
        $stateProvider.state('awayDispatch', {
            url: "/awayDispatch",
            parent: 'base',
            templateUrl: "/app/components/away_dispatch/awayDispatchListView.html",
            controller: "awayDispatchListController"
        }).state('add_awayDispatch', {
            url: "/add_awayDispatch",
            parent: 'base',
            templateUrl: "/app/components/away_dispatch/awayDispatchListView.html",
            controller: "awayDispatchAddController"
        }).state('edit_awayDispatch', {
            url: "/edit_awayDispatch/:id",
            parent: 'base',
            templateUrl: "/app/components/away_dispatch/awayDispatchListView.html",
            controller: "awayDispatchEditController"
        });
        //$urlRouterProvider.otherwise('/admin');
    }
})();


// AngularUI: thay dổi page của app base state not base route URL

// 1. tạo module, tham số add module chung(vì chứa thư viện), 
//2. inject 
//3. viet hàm được đặt ở  mục 1 với  stateProvider
