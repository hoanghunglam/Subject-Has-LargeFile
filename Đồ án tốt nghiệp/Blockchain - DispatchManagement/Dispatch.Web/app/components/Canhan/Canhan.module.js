/// <reference path="../../../Assets/admin/libs/angular/angular.js" />

(function () {
    angular.module('participant.Canhan', ['dispatch.common']).config(config);
    config.$inject = ['$stateProvider', '$urlRouterProvider'];

    function config($stateProvider) {
        $stateProvider.state('Canhan', {
            url: "/Canhan",
            parent: 'base',
            templateUrl: "/app/components/Canhan/CanhanListView.html",
            controller: "CanhanListController"
        }).state('add_Canhan', {
            url: "/add_Canhan",
            parent: 'base',
            templateUrl: "/app/components/Canhan/CanhanAddView.html",
            controller: "CanhanAddController"
            }).state('edit_Canhan', {
            url: "/edit_Canhan/:id",
            parent: 'base',
                templateUrl: "/app/components/Canhan/CanhanEditView.html",
            controller: "CanhanEditController"
        });
    }
})();
