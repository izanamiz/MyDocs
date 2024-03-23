<%@page import="model.TaiLieu075"%>
<%@page import="java.util.ArrayList"%>
<%@page import="dao.TKTaiLieuDAO075"%>
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
		<h4 class="text-center">Thống kê tài liệu theo số lượt mượn</h4>
		<%@ include file="gdChonThoiGian075.jsp"%>

		<table class="table mt-3">
			<thead>
				<tr>
				<tr>
					<th scope="col">ID</th>
					<th scope="col">Name</th>
					<th scope="col">Author</th>
					<th scope="col">Category</th>
					<th scope="col">NumBorrows</th>
					<th scope="col">Action</th>
				</tr>
			</thead>
			<tbody>
				<%
				// Lấy giá trị ngày bắt đầu và ngày kết thúc từ URL
				String beginDate = request.getParameter("beginDate");
				String endDate = request.getParameter("endDate");
				if (beginDate != null && endDate != null) {
					TKTaiLieuDAO075 tlpmDAO = new TKTaiLieuDAO075();
					ArrayList<TaiLieu075> ans = tlpmDAO.countDocsByBorrows(beginDate, endDate);
					if (ans != null) {
						for (TaiLieu075 doc : ans) {
					int docID = doc.getId();
				%>
				<tr>

					<th><%=docID%></th>
					<td><%=doc.getName()%></td>
					<td><%=doc.getAuthor()%></td>
					<td><%=doc.getCategory()%></td>
					<td><%=doc.getNumBorrows()%></td>
					<td><a
						href="<%=request.getContextPath()%>/view/gdNVQL/gdChiTietLuotMuon075.jsp?beginDate=<%=beginDate%>&endDate=<%=endDate%>&docID=<%=docID%>"><button
								type="button" class="btn btn-primary">View details</button></a></td>
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
