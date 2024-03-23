package web;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import dao.ThanhVienDAO075;
import model.ThanhVien075;

@WebServlet("/")
public class LibraryManagementServlet extends HttpServlet {

	private static final long serialVersionUID = 1L;
	private ThanhVienDAO075 tvDao = new ThanhVienDAO075();

	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {

		request.getRequestDispatcher("login075.jsp").forward(request, response);
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		HttpSession session = request.getSession();

		String username = request.getParameter("username");
		String password = request.getParameter("password");
		ThanhVien075 tv = new ThanhVien075();
		tv.setUsername(username);
		tv.setPassword(password);
		boolean res = tvDao.validate(tv);
		try {
			if (res) {

				if (tv.getRole().equalsIgnoreCase("reader")) {
					session.setAttribute("reader", tv);
					response.sendRedirect("view\\gdBanDoc\\gdChinhBanDoc075.jsp");
				} else if (tv.getRole().equalsIgnoreCase("manager")) {
					session.setAttribute("manager", tv);
					response.sendRedirect("view\\gdNVQL\\gdChinhNVQL075.jsp");
				}

			} else {
//				String resourePath = request.getContextPath();
//				response.sendRedirect(resourePath + "/login075.jsp?err=timeout");

				response.sendRedirect("login075.jsp?err=fail");
			}
		} catch (Exception e) { // TODO: handle exception
			e.printStackTrace();
			System.out.println("Exception: " + e.getMessage());
		}
	}
}
