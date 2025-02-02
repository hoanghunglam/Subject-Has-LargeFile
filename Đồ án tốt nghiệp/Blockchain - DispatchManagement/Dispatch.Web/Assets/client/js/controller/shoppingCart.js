﻿var cart = {
    init: function () {
        cart.loadData();
        cart.registerEvent();
    },
    registerEvent: function () {
        // validate la thu vien jquey
        $('#frmPayment').validate({
            // tập các quy tắc validate form
            rules: {
                name: "required",
                address: "required",
                email: {
                    required: true,
                    email:true
                },
                phone: {
                    required: true,
                    number:true
                },
            },
            messages: {
                name: "Yêu cầu nhập tên",
                address: "Yêu cầu nhập địa chỉ",
                email: {
                    required: "Bạn cần nhập email",
                    email: "Định dạng email chưa đúng"
                },
                phone: {
                    required: "Số điện thoại được yêu cầu",
                    number: "Số điện thoại phải là số."
                }
            }
        });
        cart.deleteItem();
        // xao sự kiện bind click đằng trước cho sạch

        $('.btnDeleteItem').off('click').on('click', function (e) {
            e.preventDefault();// xóa điều hướng mặc định thẻ 
            var produtId = parseInt($(this).data('id'));
            cart.deleteItem(produtId);
        });

        $('.txtQuantity').off('keyup').on('keyup', function (e) {
            e.preventDefault();// xóa điều hướng mặc định thẻ 
            var quantity = parseInt($(this).val());
            var productId = parseInt($(this).data('id'));
            var price = parseFloat($(this).data('price'));
            if (isNaN(quantity) == false) {
                var amount = quantity * price;
                $('#amount_' + productId).text(numeral(amount).format('0,0'));
            } else {
                $('#amount_' + productId).text(0);
            }
            $('#lblTotalOrder').text(numeral(cart.getTotalOrder()).format('0,0'));
            cart.updateAll();
        });
        $('#btnContinue').off('click').on('click', function (e) {
            e.preventDefault();// xóa điều hướng mặc định thẻ 
            window.location.href = "/";
        });
        $('#btnDeleteAll').off('click').on('click', function (e) {
            e.preventDefault();// xóa điều hướng mặc định thẻ 
            cart.deleteAll();
        });
        $('#btnCheckOut').off('click').on('click', function (e) {
            e.preventDefault();// xóa điều hướng mặc định thẻ 
            //window.location.href = "/pay.html";
            $('#divCheckOut').show();
        });
        $('#btnCreateOrder').off('click').on('click', function (e) {
            e.preventDefault();// xóa điều hướng mặc định thẻ 
            var isValid = $('#frmPayment').valid();
            if (isValid) {
                cart.createOrder();
            }
        });
        $('#chkUserInfo').off('click').on('click', function (e) {
            if ($(this).prop('checked') == true) {
                cart.getLoginUser();
            } else {
                $('#txtName').val('');
                $('#txtAddress').val('');
                $('#txtEmail').val('');
                $('#txtPhone').val('');
            }
        });
    },
    getLoginUser: function () {
        $.ajax({
            url: 'ShoppingCart/GetUser',
            type: 'POST',
            dataType: 'json',
            success: function (response) {
                if (response.status) {
                    var user = response.data;
                    $('#txtName').val(user.FullName);
                    $('#txtAddress').val(user.Address);
                    $('#txtEmail').val(user.Email);
                    $('#txtPhone').val(user.PhoneNumber);
                }
            }

        });
    },
    createOrder: function () {
        var order = {
            CustomerName: $('#txtName').val(),
            CustomerAddress: $('#txtAddress').val(),
            CustomerEmail: $('#txtEmail').val(),
            CustomerMobile: $('#txtPhone').val(),
            CustomerMessage: $('#txtMessage').val(),
            PaymentMethod: "Thanh toán tiền mặt",
            Status: false
        }
        $.ajax({
            url: 'ShoppingCart/CreateOrder',
            type: 'POST',
            dataType: 'json',
            data: {
                orderViewModel: JSON.stringify(order)
            },
            success: function (response) {
                if (response.status) {
                    console.log('create order ok');
                    $('#divCheckOut').hide();
                    cart.deleteAll();
                    // cho chạy 1 chút 
                    setTimeout(function () {
                        $('#cartContent').html('Cảm ơn bạn đã đặt hàng thành công. Chúng tôi sẽ liên hệ sớm nhất.');
                    }, 2000);
                }
            }

        });
    },
    loadData: function () {
        $.ajax({
            url: '/ShoppingCart/GetAll',
            type: 'GET',
            dataType: 'json',
            success: function (res) {
                if (res.status) {
                    var template = $('#tplCart').html();
                    var html = '';
                    var data = res.data;
                    $.each(data, function (i, item) {
                        html += Mustache.render(template, {
                            ProductId: item.ProductId,
                            ProductName: item.Product.Name,
                            Image: item.Product.Image,
                            Price: item.Product.Price,
                            PriceF: numeral(item.Product.Price).format('0,0'),
                            Quantity: item.Quantity,
                            Amount: numeral(item.Quantity * item.Product.Price).format('0,0'),
                        });
                    });
                    if (html == '') {
                        $('#cartContent').html('Not product in cart');
                    }
                    $('#cartBody').html(html);
                    $('#lblTotalOrder').text(numeral(cart.getTotalOrder()).format('0,0'));
                    cart.registerEvent();
                }
            }

        });
    },
    addItem: function (productId) {
        $.ajax({
            url: '/ShoppingCart/Add',
            data: {
                productId: productId
            },
            type: 'POST',
            dataType: 'json',
            success: function (response) {
                if (response.status) {
                    alert('add success!');
                }
            }

        });
    },
    deleteItem: function (productId) {
        $.ajax({
            url: 'ShoppingCart/DeleteItem',
            data: {
                productId: productId
            },
            type: 'POST',
            dataType: 'json',
            success: function (reponse) {
                if (reponse.status) {
                    cart.loadData();
                }
            }
        });
    },
    deleteAll: function () {
        $.ajax({
            url: '/ShoppingCart/DeleteAll',
            type: 'POST',
            dataType: 'json',
            success: function (reponse) {
                if (reponse.status) {
                    cart.loadData();
                }
            }
        });
    },
    getTotalOrder: function () {
        var listTextBox = $('.txtQuantity');
        var total = 0;
        $.each(listTextBox, function (i, item) {
            total += parseInt($(item).val()) * parseFloat($(item).data('price'));
        });
        return total;
    },
    updateAll: function () {
        var cartList = [];
        $('.txtQuantity').each(function (i, item) {
            cartList.push({
                ProductId: $(item).data('id'),
                Quantity: $(item).val()
            });
        });
        $.ajax({
            url: 'ShoppingCart/Update',
            data: {
                cartData: JSON.stringify(cartList)
            },
            type: 'POST',
            dataType: 'json',
            success: function (response) {
                if (response.status) {
                    cart.loadData()
                    console.log('update success!');
                }
            }

        });
    }
}
cart.init();