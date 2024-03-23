const changeBgImg = () => {
  const btnColor1 = document.querySelector("#btn-clr-1");
  const btnColor2 = document.querySelector("#btn-clr-2");
  const btnText = document.querySelector(".btn-clr-text");

  document.body.style.backgroundImage = `linear-gradient(to right, ${btnColor1.value}, ${btnColor2.value})`;
  btnText.innerHTML = `linear-gradient(to right, ${hexToDec(
    btnColor1.value
  )}, ${hexToDec(btnColor2.value)})`;
};

const hexToDec = (hex = "#ff0000") => {
  const r = parseInt(hex.substring(1, 3), 16);
  const g = parseInt(hex.substring(3, 5), 16);
  const b = parseInt(hex.substring(5, 7), 16);
  return "rgb(" + r + ", " + g + ", " + b + ")";
};
const randomHexColor = () => {
  return Math.floor(Math.random() * (256 * 256 * 256 - 1)).toString(16);
};

const randomColor = () => {
  const color1 = "#" + randomHexColor();
  const color2 = "#" + randomHexColor();

  document.querySelector(
    "body"
  ).style.backgroundImage = `linear-gradient(to right, ${color1}, ${color2})`;

  const btnColor1 = document.querySelector("#btn-clr-1");
  const btnColor2 = document.querySelector("#btn-clr-2");
  const btnText = document.querySelector(".btn-clr-text");

  btnColor1.setAttribute("value", color1);
  btnColor2.setAttribute("value", color2);

  btnText.innerHTML = `linear-gradient(to right, ${hexToDec(
    color1
  )}, ${hexToDec(color2)})`;
};
