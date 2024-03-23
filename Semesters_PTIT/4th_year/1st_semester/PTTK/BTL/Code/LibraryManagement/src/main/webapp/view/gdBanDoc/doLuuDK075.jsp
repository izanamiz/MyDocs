<%@page import="dao.DKTheBanDocDAO075"%>
<%@page import="model.TheBanDoc075"%>
<%@page import="model.ThanhVien075"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Register Lib Card</title>
<link rel="stylesheet"
	href="https://cdn.jsdelivr.net/npm/bootstrap@4.0.0/dist/css/bootstrap.min.css"
	integrity="sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm"
	crossorigin="anonymous" />
</head>
<body>
	<%@ include file="../../../navbar075.jsp"%>

	<div class="container">
		<%
		ThanhVien075 tv = (ThanhVien075) session.getAttribute("reader");

				String resourePath = request.getContextPath();
				if (tv == null) {
			response.sendRedirect(resourePath + "/login075.jsp?err=timeout");
				} else {
			TheBanDoc075 card = new TheBanDoc075();
			card.setReaderID(tv.getId());
			DKTheBanDocDAO075 dkDAO = new DKTheBanDocDAO075();
			if (dkDAO.saveLibCard(card)) {
		%>
		<div class="alert alert-success mt-5" role="alert"
			style="text-align: center">Register Library Card Successfully</div>
		<%
		} else {
		%><div class="alert alert-danger mt-5" role="alert">Register
			Library Card Failed!</div>
		<%
		}
		}
		%>

		<div class="mt-5" style="text-align: left">
			<button type="button" class="btn btn-primary"
				onClick="handleGoBack()">Go back</button>
		</div>
	</div>

	<script>
		function handleGoBack() {
			history.back();
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