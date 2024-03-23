const add = () => {
  const num1 = document.querySelector(".fi").value;
  const num2 = document.querySelector(".se").value;
  if (num1 == "" || num2 == "") {
    alert("Nhập lại");
    document.querySelector(".fi").value = "";
    document.querySelector(".se").value = "";
    document.querySelector(".ans").value = "";
  } else {
    const sum = parseInt(num1) + parseInt(num2);
    document.querySelector(".ans").value = sum;
  }
};
