<%@page import="model.ThanhVien075"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8" />
<style>
.modal.fade {
	position: absolute !important;
}

.modal-open {
	padding-right: 0 !important;
}
</style>

</head>
<body>
	<%
	ThanhVien075 tv = (ThanhVien075) session.getAttribute("reader");
	if (tv == null) {
		response.sendRedirect(request.getContextPath() + "/login075.jsp?err=timeout");
	} else {
	%>

	<div class="modal fade" id="registerModal" tabindex="-1" role="dialog"
		aria-labelledby="exampleModalLabel" aria-hidden="true">
		<div class="modal-dialog" role="document">
			<div class="modal-content">
				<div class="modal-header">
					<h5 class="modal-title" id="exampleModalLabel">Register
						Library Card</h5>
					<button type="button" class="close" data-dismiss="modal"
						aria-label="Close">
						<span aria-hidden="true">&times;</span>
					</button>
				</div>
				<div class="modal-body">
					<form>
						<div class="form-group">
							<label for="recipient-name" class="col-form-label">Name</label> <input
								type="text" class="form-control" id="name"
								value="<%=tv.getName()%>" disabled />

						</div>
						<div class="form-group">
							<label for="recipient-name" class="col-form-label">Email</label>
							<input type="text" class="form-control" id="email"
								value="<%=tv.getEmail()%>" disabled />
						</div>
						<div class="form-group">
							<label for="recipient-name" class="col-form-label">Date
								of birth</label> <input type="text" class="form-control" id="dob"
								value="<%=tv.getPhone()%>" disabled />
						</div>

						<div class="form-group">
							<label for="recipient-name" class="col-form-label">Phone
								number</label> <input type="text" class="form-control" id="phone"
								value="<%=tv.getPhone()%>" />
						</div>
						<div class="form-group">
							<label for="message-text" class="col-form-label">Address</label>
							<textarea class="form-control" id="address" disabled><%=tv.getAddress()%></textarea>

						</div>
					</form>
				</div>
				<div class="modal-footer">

					<button type="button" class="btn btn-primary" data-dismiss="modal"
						aria-label="Close" onClick="handleSubmit()">Submit</button>

				</div>
			</div>
		</div>
	</div>
	<%
	}
	%>
	
	<script>
		function handleSubmit() {
			window.location.href = 'doLuuDK075.jsp';
		}
	</script>
</body>
</html>
