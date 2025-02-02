﻿/// <reference path="../../../Assets/admin/libs/angular/angular.js" />

(function () {
    angular.module('dispatch.history', ['dispatch.common']).config(config);
    config.$inject = ['$stateProvider', '$urlRouterProvider'];

    function config($stateProvider) {
        $stateProvider.state('history_transaction', {
            url: "/history_transaction",
            parent: 'base',
            templateUrl: "/app/components/history/historyTransactionListView.html",
            controller: "historyTransactionListController"
        });
        $stateProvider.state('history_system', {
            url: "/history_system",
            parent: 'base',
            templateUrl: "/app/components/history/historySystemListView.html",
            controller: "historySystemListController"
        });
        //$urlRouterProvider.otherwise('/admin');
    }
})();


// AngularUI: thay dổi page của app base state not base route URL

// 1. tạo module, tham số add module chung(vì chứa thư viện), 
//2. inject 
//3. viet hàm được đặt ở  mục 1 với  stateProvider
