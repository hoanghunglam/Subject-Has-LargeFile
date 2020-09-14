
// controller productCategory
(function (app) {
    // khởi tạo 1 controller thực chất là khởi tạo phương thức cotroller 
    app.controller('arrivedDispatchListController', arrivedDispatchListController);
    // khởi tạo tự động các đối tượng service , và inject vào trong hàm productCategoryListController
    arrivedDispatchListController.$inject = ['$scope', 'apiService', 'notificationService', '$ngBootbox', 'authData'];

    function arrivedDispatchListController($scope, apiService, notificationService, $ngBootbox, authData) {

        $scope.getDispatch;
        $scope.getDispatchList = getDispatchList;
        $scope.keyword = '';
        $scope.urlDispatch = 'https://ipfs.io/ipfs/';
        $scope.deleteDispatch = deleteDispatch;
        $scope.confirmDispatch = confirmDispatch;
        $scope.searchProduct = searchProduct;

        function getDispatchList() {
            apiService.getBlock('http://' + hostLam + ':3000/api/org.dispatch.CongVanDen', {
                headers: {
                    'X-Access-Token': access_tokens
                }
            }, function (result) {
                if (result.data.TotaCount == 0) {
                    notificationService.displayWarning('Không có dữ liệu!');
                }
                $scope.getDispatch = result.data;
                for (var i = 0; i < $scope.getDispatch.length; i++) {
                    var ngayPhatHanh = $scope.getDispatch[i].ngayPhatHanh.split("T");
                    $scope.getDispatch[i].ngayPhatHanh = ngayPhatHanh[0];
                    var ngayTao = $scope.getDispatch[i].ngayTao.split("T");
                    $scope.getDispatch[i].ngayTao = ngayTao[0];
                    var nguoiKy = $scope.getDispatch[i].nguoiKy.split("#");
                    if (nguoiKy[1] != "%20") {
                        $scope.getDispatch[i].nguoiKy = nguoiKy[1];
                    }
                    else $scope.getDispatch[i].nguoiKy = "";
                    var nguoiKyNhay = $scope.getDispatch[i].nguoiKyNhay.split("#");
                    if (nguoiKyNhay[1] != "%20") {
                        $scope.getDispatch[i].nguoiKyNhay = nguoiKyNhay[1];
                    }
                    else $scope.getDispatch[i].nguoiKyNhay = "";
                    var nguoiGui = $scope.getDispatch[i].nguoiGui.split("#");
                    if (nguoiGui[1] != "%20") {
                        $scope.getDispatch[i].nguoiGui = nguoiGui[1];
                    }
                    else $scope.getDispatch[i].nguoiGui = "";
                    var nguoiDuyet = $scope.getDispatch[i].nguoiDuyet.split("#");
                    if (nguoiDuyet[1] != "%20") {
                        $scope.getDispatch[i].nguoiDuyet = nguoiDuyet[1];
                    }
                    else $scope.getDispatch[i].nguoiDuyet = "";

                    switch ($scope.getDispatch[i].kieu) {
                        case "Chithi_CT":
                            $scope.getDispatch[i].kieu = "Chỉ thỉ";
                            break;
                        case "Bancamket_CK":
                            $scope.getDispatch[i].kieu = "Bản cam kết";
                            break;
                        case "Banghinho_GN":
                            $scope.getDispatch[i].kieu = "Bản ghi nhớ";
                            break;
                        case "Bansaoluc_SL":
                            $scope.getDispatch[i].kieu = "Bản sao lục";
                            break;
                        case "Bansaoybanchinh_SY":
                            $scope.getDispatch[i].kieu = "Bản sao y bản chính";
                            break;
                        case "Banthoathuan_TTh":
                            $scope.getDispatch[i].kieu = "Bản thỏa thuận";
                            break;
                        case "Bantrichsao_TS":
                            $scope.getDispatch[i].kieu = "Bản trích sao";
                            break;
                        case "Baocao_BC":
                            $scope.getDispatch[i].kieu = "Báo cáo";
                            break;
                        case "Bienban_BB":
                            $scope.getDispatch[i].kieu = "Biên bản";
                            break;
                        case "Bieumauthongke_BMTK":
                            $scope.getDispatch[i].kieu = "Biểu mẫu thống kê";
                            break;
                        case "Chuongtrinh_CTr":
                            $scope.getDispatch[i].kieu = "Chương trình";
                            break;
                        case "Congdien_CD":
                            $scope.getDispatch[i].kieu = "Công điện";
                            break;
                        case "Danhsach_DS":
                            $scope.getDispatch[i].kieu = "Danh sách";
                            break;
                        case "Duan_DA":
                            $scope.getDispatch[i].kieu = "Dự án";
                            break;
                    }
                    switch ($scope.getDispatch[i].tinhTrang) {
                        case "Dang_xu_ly":
                            $scope.getDispatch[i].tinhTrang = "Đang chờ duyệt";
                            break;
                        case "Da_xu_ly":
                            $scope.getDispatch[i].tinhTrang = "Đã duyệt";
                            break;
                    }
                }
                console.log(result);
                console.log(result.data);
            }, function (error) {
                notificationService.displayError('Tải dữ liệu không thành công!');
                console.log(error.data + 'Load data failed!');
            });
        }
        $scope.getDispatchList();

        function searchProduct() { }


        $scope.confirmer = {
            $class: 'org.dispatch.NhanCongVanDen',
            congVan: '',
            nguoiDuyet: '',
            //tranctionId: '',
            //timestamp: '',
        }

        function deleteDispatch(ID) {
            $ngBootbox.confirm("Bạn chắc chắn muốn xóa!").then(function () {
                apiService.delBlock('http://' + hostLam + ':3000/api/org.dispatch.CongVanDen/' + ID, {
                    headers: {
                        'X-Access-Token': access_tokens
                    }
                }, function () {
                    notificationService.displaySuccess('Công văn đã xóa!');
                    $scope.getDispatchList();
                }, function (error) {
                    console.log(error);
                    notificationService.displayWarning('Xóa không thành công!');
                });
            });
        }

        /*var ngay = new Date().getDate();
        var thang = new Date().getMonth();
        thang++;
        var nam = new Date().getFullYear();
        if (thang < 10) {
            $scope.confirmer.timestamp = "" + nam + "-0" + thang + "-" + ngay;
        }
        else $scope.confirmer.timestamp = "" + nam + "-" + thang + "-" + ngay;*/

        function confirmDispatch(ID) {
            $ngBootbox.confirm("Bạn chắc chắn muốn duyệt công văn này?").then(function () {
                $scope.confirmer.congVan = ID;
                //$scope.confirmer.tranctionId = Math.random().toString(30);
                apiService.postBlock('http://' + hostLam + ':3000/api/org.dispatch.NhanCongVanDen/', $scope.confirmer, {
                    headers: {
                        'X-Access-Token': access_tokens
                    }
                }, function () {
                    notificationService.displaySuccess('Công văn đã được phê duyệt!');
                    $scope.getDispatchList();
                }, function (error) {
                    console.log(error);
                    notificationService.displayWarning('Phê duyệt không thành công!');
                });
            });
        }
        function loginUserCard() {
            $scope.loading = true;
            var url = 'http://' + hostLam + ':3000/api/wallet/' + authData.authenticationData.userName + '@dispatch-management/setDefault';
            apiService.postBlock(url, null,
                {
                    headers: {
                        'X-Access-Token': access_tokens
                    }
                },
                function (res) {
                    console.log(res);
                    getDispatchList();
                }, function (err) {
                    console.log(err);
                    notificationService.displayError(err.data.error.message);
                    $scope.loading = false;

                });
                apiService.getBlock('http://' + hostLam + ':3000/api/system/ping', {
                    headers:
                        { 'X-Access-Token': access_tokens }
                }, function (result) {
                    $scope.confirmer.nguoiDuyet = result.data.participant;
                    console.log($scope.confirmer.nguoiDuyet);
                }, function (er) {
                    console.log(er);
                });
        }
        loginUserCard();

    }
})(angular.module('dispatch.arrivedDispatch'));