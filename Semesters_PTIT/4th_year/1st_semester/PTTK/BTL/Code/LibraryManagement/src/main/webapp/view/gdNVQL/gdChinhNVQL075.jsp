<%@page import="model.ThanhVien075"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8" />
<title>LibMan</title>
<link rel="stylesheet"
	href="https://cdn.jsdelivr.net/npm/bootstrap@4.0.0/dist/css/bootstrap.min.css"
	integrity="sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm"
	crossorigin="anonymous" />

<style>
.dropdown-menu {
	right: 0 !important;
	left: unset !important;
	min-width: unset !important;
}
</style>
</head>
<body>


	<%
	ThanhVien075 tv = (ThanhVien075) session.getAttribute("manager");
	String resourePath = request.getContextPath();

	if (tv == null) {
		response.sendRedirect(resourePath + "/login075.jsp?err=timeout");
	} else {
	%>
	<%@ include file="../../../navbar075.jsp"%>

	<div class="container text-center mt-5">
		<h4 class="mb-3">
			Hello manager
			<%=tv.getName()%>!
		</h4>

		<div class="row">
			<div class="col">
				<button type="button" class="btn btn-primary"
					onClick="hanldeViewReports()">View reports</button>
			</div>
		</div>
	</div>

	<%
	}
	%>

	<script>
		function hanldeViewReports() {
			window.location.href = 'gdXemBaoCao075.jsp';
		}
	</script>
	<script src="https://code.jquery.com/jquery-3.2.1.slim.min.js"
		integrity="sha384-KJ3o2DKtIkvYIK3UENzmM7KCkRr/rE9/Qpg6aAZGJwFDMVNA/GpGFF93hXpG5KkN"
		crossorigin="anonymous"></script>
	<script
		src="https://cdn.jsdelivr.net/npm/popper.js@1.12.9/dist/umd/popper.min.js"
		integrity="sha384-ApNbgh9B+Y1QKtv3Rn7W3mgPxhU9K/ScQsAP7hUibX39j7fakFPskvXusvfa0b4Q"
		crossorigin="anonymous"></script>
	<script
		src="https://cdn.jsdelivr.net/npm/bootstrap@4.0.0/dist/js/bootstrap.min.js"
		integrity="sha384-JZR6Spejh4U02d8jOt6vLEHfe/JQGiRRSQQxSfFWpi1MquVdAyjUar5+76PVCmYl"
		crossorigin="anonymous"></script>
</body>
</html>
