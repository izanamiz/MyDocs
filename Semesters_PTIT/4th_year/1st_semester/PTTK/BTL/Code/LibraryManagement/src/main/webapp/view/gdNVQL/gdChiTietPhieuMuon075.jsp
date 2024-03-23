
<%@page import="java.util.Date"%>
<%@page import="java.text.SimpleDateFormat"%>
<%@page import="model.PhieuMuon075"%>
<%@page import="model.TaiLieu075"%>
<%@page import="java.util.ArrayList"%>
<%@page import="dao.PhieuMuonDAO075"%>
<%@page import="model.ThanhVien075"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8" />
<title>Statistic</title>
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

	<div class="container  mt-5">
		<h4 class="text-center">Phiếu mượn tài liệu</h4>

		<%
		String receiptID = request.getParameter("receiptID");

		if (receiptID != null) {
			PhieuMuonDAO075 pmDAO = new PhieuMuonDAO075();
			PhieuMuon075 pm = new PhieuMuon075();

			ArrayList<TaiLieu075> ans = pmDAO.viewReceipt(receiptID, pm);

			if (ans != null) {
		%>
		<div class="row mt-5">
			<div class="col" style="font-weight: bold">
				ReceiptID:
				<%=pm.getId()%></div>
			<div class="col text-right" style="font-weight: bold">
				Date:
				<%
			String inputDateString = pm.getDate();
			SimpleDateFormat inputFormat = new SimpleDateFormat("yyyy-MM-dd");
			SimpleDateFormat outputFormat = new SimpleDateFormat("dd-MM-yyyy");

			Date date = inputFormat.parse(inputDateString);
			String outputDateString = outputFormat.format(date);
			%>
				<%=outputDateString%>
			</div>
		</div>
		<div class="row mt-3">
			<div class="col" style="font-weight: bold">
				CardID:
				<%=pm.getCardID()%></div>
			<div class="col text-right" style="font-weight: bold">
				ReaderName:
				<%=pm.getName()%></div>
		</div>

		<table class="table mt-5">
			<thead>
				<tr>
				<tr>
					<th scope="col">DocID</th>
					<th scope="col">Name</th>
					<th scope="col">Author</th>
					<th scope="col">Action</th>
				</tr>
			</thead>
			<tbody>

				<%
				for (TaiLieu075 doc : ans) {
				%><tr>
					<th><%=doc.getId()%></th>
					<td><%=doc.getName()%></td>
					<td><%=doc.getAuthor()%></td>
					<td><button class="btn btn-primary disabled">View</button></td>
				</tr>
				<%
				}
				%>

			</tbody>
		</table>
		<p style="font-weight: bold">
			Quantity:
			<%=ans.size()%>
		</p>
		<%
		}
		}
		%>
	</div>
	<%
	}
	%>
	<script>
		function handleViewDetails(docID) {

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
