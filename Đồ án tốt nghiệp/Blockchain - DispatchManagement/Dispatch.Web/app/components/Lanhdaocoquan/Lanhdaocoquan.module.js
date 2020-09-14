/// <reference path="../../../Assets/admin/libs/angular/angular.js" />

(function () {
    angular.module('participant.Lanhdaocoquan', ['dispatch.common']).config(config);
    config.$inject = ['$stateProvider', '$urlRouterProvider'];

    function config($stateProvider, $urlRouterProvider) {
        $stateProvider.state('Lanhdaocoquan', {
            url: "/Lanhdaocoquan",
            parent: 'base',
            templateUrl: "/app/components/Lanhdaocoquan/LanhdaocoquanListView.html",
            controller: "LanhdaocoquanListController"
        }).state('add_Lanhdaocoquan', {
            url: "/add_Lanhdaocoquan",
            parent: 'base',
            templateUrl: "/app/components/Lanhdaocoquan/LanhdaocoquanAddView.html",
            controller: "LanhdaocoquanAddController"
        }).state('edit_Lanhdaocoquan', {
            url: "/edit_Lanhdaocoquan/:id",
            parent: 'base',
            templateUrl: "/app/components/Lanhdaocoquan/LanhdaocoquanEditView.html",
            controller: "LanhdaocoquanEditController"
        });
        //$urlRouterProvider.otherwise('/admin');
    }
})();


// AngularUI: thay dổi page của app base state not base route URL

// 1. tạo module, tham số add module chung(vì chứa thư viện), 
//2. inject 
//3. viet hàm được đặt ở  mục 1 với  stateProvider
