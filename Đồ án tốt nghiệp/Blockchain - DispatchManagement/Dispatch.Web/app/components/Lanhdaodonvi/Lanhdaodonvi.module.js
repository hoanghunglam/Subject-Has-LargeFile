/// <reference path="../../../Assets/admin/libs/angular/angular.js" />

(function () {
    angular.module('participant.Lanhdaodonvi', ['dispatch.common']).config(config);
    config.$inject = ['$stateProvider', '$urlRouterProvider'];

    function config($stateProvider, $urlRouterProvider) {
        $stateProvider.state('Lanhdaodonvi', {
            url: "/Lanhdaodonvi",
            parent: 'base',
            templateUrl: "/app/components/Lanhdaodonvi/LanhdaodonviListView.html",
            controller: "LanhdaodonviListController"
        }).state('add_Lanhdaodonvi', {
            url: "/add_Lanhdaodonvi",
            parent: 'base',
            templateUrl: "/app/components/Lanhdaodonvi/LanhdaodonviAddView.html",
            controller: "LanhdaodonviAddController"
        }).state('edit_Lanhdaodonvi', {
            url: "/edit_Lanhdaodonvi/:id",
            parent: 'base',
            templateUrl: "/app/components/Lanhdaodonvi/LanhdaodonviEditView.html",
            controller: "LanhdaodonviEditController"
        });
        //$urlRouterProvider.otherwise('/admin');
    }
})();


// AngularUI: thay dổi page của app base state not base route URL

// 1. tạo module, tham số add module chung(vì chứa thư viện), 
//2. inject 
//3. viet hàm được đặt ở  mục 1 với  stateProvider
