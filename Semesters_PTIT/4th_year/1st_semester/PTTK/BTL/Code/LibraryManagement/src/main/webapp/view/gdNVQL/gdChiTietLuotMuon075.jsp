
<%@page import="dao.TaiLieuPhieuMuonDAO075"%>
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

	<div class="container mt-5">
		<h4 class="text-center">Chi tiết những lần tài liệu được mượn</h4>

		<%
		String docID = request.getParameter("docID");
		String beginDate = request.getParameter("beginDate");
		String endDate = request.getParameter("endDate");

		if (docID != null && beginDate != null && endDate != null) {
			TaiLieuPhieuMuonDAO075 pmDAO = new TaiLieuPhieuMuonDAO075();
			TaiLieu075 tl = new TaiLieu075();

			ArrayList<PhieuMuon075> ans = pmDAO.viewDetails(docID, beginDate, endDate, tl);

			if (ans != null) {
		%>

		<div class="mt-5" style="font-weight: bold">
			DocID:
			<%=tl.getId()%></div>
		<div class="mt-3" style="font-weight: bold">
			DocName:
			<%=tl.getName()%></div>


		<table class="table mt-5">
			<thead>
				<tr>
				<tr>
					<th scope="col">ReceiptID</th>
					<th scope="col">Date</th>
					<th scope="col">CardID</th>
					<th scope="col">ReaderName</th>
					<th scope="col">Action</th>
				</tr>
			</thead>
			<tbody>

				<%
				for (PhieuMuon075 pm : ans) {
					int receiptID = pm.getId();
				%><tr>
					<th><%=receiptID%></th>
					<td>
						<%
						String inputDateString = pm.getDate();
						SimpleDateFormat inputFormat = new SimpleDateFormat("yyyy-MM-dd");
						SimpleDateFormat outputFormat = new SimpleDateFormat("dd-MM-yyyy");

						Date date = inputFormat.parse(inputDateString);
						String outputDateString = outputFormat.format(date);
						%> <%=outputDateString%>
					</td>
					<td><%=pm.getCardID()%></td>
					<td><%=pm.getName()%></td>
					<td><a
						href="<%=request.getContextPath()%>/view/gdNVQL/gdChiTietPhieuMuon075.jsp?receiptID=<%=receiptID%>"><button
								type="button" class="btn btn-primary">View receipt</button></a></td>
				</tr>
				<%
				}
				}
				}
				%>
			</tbody>
		</table>
	</div>
	<%
	}
	%>

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
