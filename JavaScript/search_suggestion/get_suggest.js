var _completeDiv;
var _inputField;
var _current_result;
var _current_input_field_value;
var _old_input_field_value;
var ca = 1;
var p;
var aa;
var box = ["食宿", "H",
           "票费", "T",
           "资讯", "O",
           "路线", "R",
           "旅行社", "A"];
var _select_index;
var _host;

function initSearch()
{
  _completeDiv = document.getElementById("result");
  _inputField = document.getElementById("queryword");
  _current_result = _completeDiv;
  _current_input_field_value = "";
  _old_input_field_value = "";
  _select_index = -1;           // -1 means the cursor is in the input field currently
  _host = "";
  _inputField.focus();

  /*
   * Make the input field be center.
   * Set the 'position' attribute in non-IE browser.
   */
  if (navigator && navigator.userAgent.toLowerCase().indexOf("msie") == -1)
  {
    document.getElementById("search_field").style.position = "absolute";
  }

  /*
   * Set the position and size of suggest search division.
   */
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

function db()
{
  var wb = 110;
  var Sa = calculateWidth();
  var tb = (Sa - wb) / Sa * 100;
  p = tb;
}

function setStyleForElement(c, name)
{
  db();
  c.className = name;
  // if(Ka)
  // {
  //   return;
  // }
  switch (name.charAt(0))
  {
    // case "m":
    //   c.style.fontSize = "13px";
    //   c.style.fontFamily = "arial, sans-serif";
    //   c.style.wordWrap = "break-word";
    //   break;
    case "l":
      c.style.display = "block";
      c.style.paddingLeft = "3px";
      c.style.paddingRight = "3px";
      c.style.height = "19px";
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
      c.style.backgroundColor = "#3366CC";
      c.style.color = "white";
      c.style.cursor = "default";
      if(c.displaySpan)
      {
        c.displaySpan.style.color = "white";
      }
      break;
    case "c":
      c.style.width = p + "%";

      /*
       * IE use 'styleFloat', other use 'cssFloat'.
       */
      if (navigator && navigator.userAgent.toLowerCase().indexOf("msie") == -1)
      {
        c.style.cssFloat = "left";
      }
      else
      {
        c.style.styleFloat = "left";
      }

      c.style.textAlign = "left";
      break;
    case "d":
      /*
       * IE use 'styleFloat', other use 'cssFloat'.
       */
      if (navigator && navigator.userAgent.toLowerCase().indexOf("msie") == -1)
      {
        c.style.cssFloat = "right";
      }
      else
      {
        c.style.styleFloat = "right";
      }

      c.style.width = 100 - p + "%";
      c.style.fontSize = "13px";
      c.style.textAlign = "right";
      c.style.color = "green";
      c.style.paddingTop = "3px";
      break;
    case "e":
      c.style.backgroundColor = "#FFE69A";
      c.style.height = "3px";
      break;
  }
}

function findSpanValueForClass(d, c)
{
  var sp = d.getElementsByTagName("span");
  if (sp)
  {
    for (var i = 0; i != sp.length; ++i)
      if (sp[i].className == c)
        return sp[i].innerHTML;
    return "";
  }
}

var mover = function()
{
  // if (_highlightedSuggestionDiv)
  // {
  //   setStyleForElement(_highlightedSuggestionDiv, "aAutoComplete");
  // }

  var child_nodes = _completeDiv.childNodes;

  /*
   * Cancel the selection by keyboard.
   */
  if (_select_index != -1)
  {
    setStyleForElement(child_nodes[_select_index], "aAutoComplete");
  }

  setStyleForElement(this, "bAutoComplete");
  for (var i = 0; i != child_nodes.length; ++i)
    if (child_nodes[i] == this)
    {
      _select_index = i;
      break;
    }
};
// var mout = function()
// {
//   setStyleForElement(this, "aAutoComplete");
// };
var mdown = function()
{
  _inputField.value = findSpanValueForClass(this, "cAutoComplete");
  document.getElementById("f").submit();
};
var mdown_2 = function()
{
  var alist = findSpanValueForClass(this, "dAutoComplete");
  var blist = alist.substring(1, alist.length - 1);
  var type;
  for (var i = 0; i != box.length; ++i)
    if (box[i] == blist)
    {
      type = box[i + 1];
      break;
    }
  window.location = _host + "fcgi-bin/type.fcg?type=" + type + "&q=" + _inputField.value;
};

function getSuggest()
{
  var query_word = _inputField.value;
  if (!query_word)
  {
    _current_result.style.visibility = "hidden";
    return;
  }
  $.get("fcgi-bin/response.fcg", { q: query_word },
        function(data)
        {
          /*
           * If there's no suggestion for the query word, then return.
           */
          if (data.match(/error/) != null)
          {
            _current_result.style.visibility = "hidden";
            return;
          }

          _current_result.style.visibility = "visible";
          var temp_result = data.split(" ");
          var suggest_word = [];
          var word_count = [];

          /*
           * Get the suggest word and its count.
           */
          for (var i = 0, j = 0; i < temp_result.length - 2; i += 2, ++j)
          {
            suggest_word[j] = temp_result[i];
            word_count[j] = temp_result[i + 1] + " 关注度";
          }

          /*
           * Clear last suggest list.
           */ 
          while (_completeDiv.childNodes.length > 0)
            _completeDiv.removeChild(_completeDiv.childNodes[0]);

          /*
           * Construct the suggest list and handle the events.
           */
          for (var i = 0; i != suggest_word.length; ++i)
          {
            var u = document.createElement("div");
            setStyleForElement(u, "aAutoComplete");
            u.onmouseover = mover;
            // u.onmouseout = mout;
            u.onmousedown = mdown;
            var ka = document.createElement("span");
            setStyleForElement(ka, "lAutoComplete");
            var ua = document.createElement("span");
            setStyleForElement(ua, "cAutoComplete");
            ua.innerHTML = suggest_word[i];
            var ea = document.createElement("span");
            setStyleForElement(ea, "dAutoComplete");
            ea.innerHTML = word_count[i];
            u.displaySpan = ea;
            ka.appendChild(ua);
            ka.appendChild(ea);
            u.appendChild(ka);
            _completeDiv.appendChild(u);
          }

          var a = document.createElement("div");
          setStyleForElement(a, "eAutoComplete");
          _completeDiv.appendChild(a);

          for (var i = 0; i < box.length; i += 2)
          {
            var u = document.createElement("div");
            setStyleForElement(u, "aAutoComplete");
            u.onmouseover = mover;
            // u.onmouseout = mout;
            u.onmousedown = mdown_2;
            var ka = document.createElement("span");
            setStyleForElement(ka, "lAutoComplete");            
            var ua = document.createElement("span");
            setStyleForElement(ua, "cAutoComplete");
            ua.innerHTML = "\"" + query_word + "\"的相关";
            var ea = document.createElement("span");
            setStyleForElement(ea, "dAutoComplete");
            ea.innerHTML = "[" + box[i] + "]";
            u.displaySpan = ea;
            ka.appendChild(ua);
            ka.appendChild(ea);
            u.appendChild(ka);
            _completeDiv.appendChild(u);
          }
        },
        "text");
}

function hideResult()
{
  if (_current_result != null)
    _current_result.style.visibility = "hidden";
}

function mainLoop()
{
  if (_select_index == -1)
  {
    _current_input_field_value = _inputField.value;
  }
  if (_current_input_field_value != _old_input_field_value)
  {
    _old_input_field_value = _current_input_field_value;
    getSuggest();
  }
  setTimeout("mainLoop()", 100);
}

// setTimeout("mainLoop()", 100);

/*
 * Capture the keyboard event, so that do something when some specific keys pressed.
 */
function keyEvent(event)
{
  /*
   * Get the event object and character code in a portable way.
   */
  var e = event || window.event; // key event object
  var code = e.charCode || e.keyCode; // what key was pressed
  // alert(code);

  var child_nodes = _completeDiv.childNodes;
  var unselect_index = -1;
  var line_pos;

  /*
   * Find the line's position.
   */
  for (var i = 0; i != child_nodes.length; ++i)
  {
    var class_name = child_nodes[i].attributes["class"].value;
    if (class_name == "eAutoComplete")
    {
      line_pos = i;
      break;
    }
  }

  /*
   * 38: up cursor           40: down cursor
   * 
   * 13: Enter
   *
   * 27: Esc
   * 
   * 37: left cursor         39: right cursor
   * 36: Home                35: End
   * 20: Caps Lock           16: Shift
   * 17: Ctrl                18: Alt
   * 33: Page Up             34: Page Down
   * 19: Pause Break         0: Win
   * 144: Num Lock           145: Scroll Lock
   * 9: Tab
   */
  if (code == 38)
  {
    if (_select_index == -1)
    {
      unselect_index = -1;
      _select_index = child_nodes.length - 1;
    }
    else
    {
      unselect_index = _select_index;
      if (_select_index - 1 == line_pos)
        _select_index -= 2;
      else
        --_select_index;
    }

    if (_select_index != -1)
      setStyleForElement(child_nodes[_select_index], "bAutoComplete");
    if (unselect_index != -1)
      setStyleForElement(child_nodes[unselect_index], "aAutoComplete");
  }
  else if (code == 40)
  {
    if (_select_index == child_nodes.length - 1)
    {
      unselect_index = _select_index;
      _select_index = -1;
    }
    else
    {
      unselect_index = _select_index;
      if (_select_index + 1 == line_pos)
        _select_index += 2;
      else
        ++_select_index;
    }

    if (_select_index != -1)
      setStyleForElement(child_nodes[_select_index], "bAutoComplete");
    if (unselect_index != -1)
      setStyleForElement(child_nodes[unselect_index], "aAutoComplete");
  }
  else if (code == 13)
  {
    if (_select_index > line_pos)
    {
      var alist = findSpanValueForClass(child_nodes[_select_index], "dAutoComplete");
      var blist = alist.substring(1, alist.length - 1);
      var type;
      for (var i = 0; i < box.length; i += 2)
        if (box[i] == blist)
        {
          type = box[i + 1];
          break;
        }
      window.location = _host + "fcgi-bin/type.fcg?type=" + type + "&q=" + _old_input_field_value;
    }
    else
    {
      document.getElementById("f").submit();
    }
  }
  else if (code == 27)
  {
    hideResult();
  }
  else if (code == 37 || code == 39 || code == 36 || code == 35 ||
           code == 20 || code == 16 || code == 17 || code == 18 ||
           code == 33 || code == 34 || code == 19 || code == 0 ||
           code == 144 || code == 145 || code == 9)
  {
    return;
  }
  else
  {
    _select_index = -1;
    return;
  }

  if (_select_index == -1)
    _inputField.value = _old_input_field_value;
  else
  {
    if (_select_index > line_pos)
    {
      _inputField.value = findSpanValueForClass(child_nodes[_select_index], "cAutoComplete") + findSpanValueForClass(child_nodes[_select_index], "dAutoComplete");
    }
    else
      _inputField.value = findSpanValueForClass(child_nodes[_select_index], "cAutoComplete");
  }
}