
(function () {
    angular.module('participant.VanthuBo', ['dispatch.common']).config(config);
    config.$inject = ['$stateProvider', '$urlRouterProvider'];

    function config($stateProvider) {
        $stateProvider.state('VanthuBo', {
            url: "/VanthuBo",
            parent: 'base',
            templateUrl: "/app/components/VanthuBo/VanthuBoListView.html",
            controller: "VanthuBoListController"
        }).state('add_VanthuBo', {
            url: "/add_VanthuBo",
            parent: 'base',
            templateUrl: "/app/components/VanthuBo/VanthuBoAddView.html",
            controller: "VanthuBoAddController"
        }).state('edit_VanthuBo', {
            url: "/edit_VanthuBo/:id",
            parent: 'base',
            templateUrl: "/app/components/VanthuBo/VanthuBoEditView.html",
            controller: "VanthuBoEditController"
        });
    }
})();