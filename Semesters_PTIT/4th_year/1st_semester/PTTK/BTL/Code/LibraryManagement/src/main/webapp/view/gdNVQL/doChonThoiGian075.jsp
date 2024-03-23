<%@page import="model.ThanhVien075"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8" />

<style>
.dropdown-menu {
	right: 0 !important;
	left: unset !important;
	min-width: unset !important;
}
</style>
</head>
<body>

	<div class="row mt-3">
		<div class="col">
			<div class="form-group">
				<label for="datePicker">Chọn ngày bắt đầu:</label> <input
					type="date" class="form-control" id="begin">
			</div>
		</div>
		<div class="col">
			<div class="form-group">
				<label for="datePicker">Chọn ngày kết thúc:</label> <input
					type="date" class="form-control" id="end">
			</div>
		</div>
		<div class="col">
			<div
				style="display: flex; height: 100%; width: 100%; justify-content: center !important; align-items: center !important;">
				<button type="button" class="btn" onClick="handleViewReports()">View
					Statistic</button>
			</div>

		</div>
	</div>


	<script>
		var urlParams = new URLSearchParams(window.location.search);
		if (urlParams.has('beginDate')) {
			var beginDate = urlParams.get('beginDate');
			document.getElementById('begin').value = beginDate;
		}

		if (urlParams.has('endDate')) {
			var endDate = urlParams.get('endDate');
			document.getElementById('end').value = endDate;
		}

		function handleViewReports() {
			var beginDate = document.getElementById("begin").value;
			var endDate = document.getElementById("end").value;

			var url = 'gdTKTaiLieu075.jsp?beginDate=' + beginDate + '&endDate='
					+ endDate;

			window.location.href = url;
		}
	</script>
</body>
</html>