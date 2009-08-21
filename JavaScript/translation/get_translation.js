var current_result;
var _completeDiv;
var _inputField;
var ca = 1;

function initSearch()
{
  _completeDiv = document.getElementById("result");
  _inputField = document.getElementById("queryword");
  setCompleteDivSize();
}

function calculateWidth()
{
  if (navigator && navigator.userAgent.toLowerCase().indexOf("msie") == -1)
  {
    return _inputField.offsetWidth - ca * 2;
  }
  else
  {
    return _inputField.offsetWidth;
  }
}

function calculateOffsetLeft(r)
{
  return Ya(r, "offsetLeft");
}

function calculateOffsetTop(r)
{
  return Ya(r, "offsetTop");
}

function Ya(r, attr)
{
  var kb = 0;
  while (r)
  {
    kb += r[attr];
    r = r.offsetParent;
  }
  return kb;
}

function setCompleteDivSize()
{
  if (_completeDiv)
  {
    _completeDiv.style.left = calculateOffsetLeft(_inputField) + "px";
    _completeDiv.style.top = calculateOffsetTop(_inputField) + _inputField.offsetHeight - 1 + "px";
    _completeDiv.style.width = calculateWidth() + "px";
  }
}

// function db()
// {
//   p = 65;
//   if (w == "query")
//   {
//     var wb = 110;
//     var Sa = calculateWidth();
//     var tb = (Sa - wb) / Sa * 100;
//     p = tb;
//   }
//   else
//   {
//     p = 65;
//   }
//   if (ya)
//   {
//     p = 99.99;
//   }
// }

function setStyleForElement(c, name)
{
  // db();
  c.className = name;
  // if(Ka)
  // {
  //   return;
  // }
  switch (name.charAt(0))
  {
    case "m":
      c.style.fontSize = "13px";
      c.style.fontFamily = "arial, sans-serif";
      c.style.wordWrap = "break-word";
      break;
    case "l":
      c.style.display = "block";
      c.style.paddingLeft = "3";
      c.style.paddingRight = "3";
      c.style.height = "16px";
      c.style.overflow = "hidden";
      break;
    case "a":
      c.style.backgroundColor = "white";
      c.style.color = "black";
      if (c.displaySpan)
      {
        c.displaySpan.style.color = "green";
      }
      break;
    case "b":
      c.style.backgroundColor = "#3366cc";
      c.style.color = "white";
      if(c.displaySpan)
      {
        c.displaySpan.style.color = "white";
      }
      break;
    case "c":
      // c.style.width = p + "%";
      c.style.cssFloat = "left";
      break;
    case "d":
      c.style.cssFloat = "right";
      // c.style.width = 100 - p + "%";
      if (w == "query")
      {
        c.style.fontSize = "10px";
        c.style.textAlign = "right";
        c.style.color = "green";
        c.style.paddingTop = "3px";
      }
      else
      {
        c.style.color = "#696969";
      }
      break;
  }
}

var mover = function()
{
  // if (_highlightedSuggestionDiv)
  // {
  //   setStyleForElement(_highlightedSuggestionDiv, "aAutoComplete");
  // }
  setStyleForElement(this, "bAutoComplete");
};
var mout = function()
{
  setStyleForElement(this, "aAutoComplete");
};

function getTranslation()
{
  current_result = document.getElementById("result");
  current_result.style.visibility = "visible";

  var q = document.getElementById("queryword").value;
  // q = q.replace(/(^\s+|\s+$)/, "");
  // q = q.replace(/\s+/g, "-");
  // var query_path = "http://www.dict.cn/" + q + ".htm";
  var query_path = "http://222.18.151.236/fcgi-bin/response.fcg?q=" + encodeURI(q);
  alert(query_path);
  $.get("proxy.php", { path: query_path },
    function(data)
    {
      // if (data.indexOf("href") != -1)
      // {
      //   data = data.replace(/\/(?=.+\.htm)/g, "http://www.dict.cn/");
      // }

      // if (data.indexOf("pronounce") != -1)
      // {
      //   var pronounce_start = data.indexOf("pronounce") + 11;
      //   var pronounce_end = data.indexOf("/span", pronounce_start) - 1;
      //   var pronounce = data.slice(pronounce_start, pronounce_end) + "<br><br>";
      // }
      // else
      // {
      //   var pronounce = "";
      // }

      // if (data.indexOf("mut_jies") != -1)
      // {
      //   var trans_start = data.indexOf("mut_jies") + 10;
      //   var trans_end = data.indexOf("/div", trans_start) - 1;
      //   var trans = data.slice(trans_start, trans_end);
      // }
      // else
      // {
      //   var trans = "";
      // }

      // if (pronounce == "" && trans == "")
      //   var r = "你是来打酱油的吗?";
      // else
      //   var r = pronounce + trans;

      // var suggest = ["都江偃",
      //   "青城山",
      //   "杜甫草堂",
      //   "九寨沟",
      //   "峨眉山",
      //   "西岭雪山",
      //   "武侯祠",
      //   "木兰山",
      //   "欢乐谷",
      //   "国色天香"];
 
      // while (_completeDiv.childNodes.length > 0)
      //   _completeDiv.removeChild(_completeDiv.childNodes[0]);

      // for (var i = 0; i != suggest.length; ++i)
      // {
      //   var u = document.createElement("div");
      //   setStyleForElement(u, "aAutoComplete");
      //   u.onmouseover = mover;
      //   u.onmouseout = mout;
      //   var ka = document.createElement("span");
      //   setStyleForElement(ka, "lAutoComplete");
      //   var ua = document.createElement("span");
      //   setStyleForElement(ua, "cAutoComplete");
      //   ua.innerHTML = suggest[i];
      //   ka.appendChild(ua);
      //   u.appendChild(ka);
      //   document.getElementById("result").appendChild(u);
      // }

      alert(data);
    },
    "html");
}

function hideResult()
{
  if (current_result != null)
    current_result.style.visibility = "hidden";
}