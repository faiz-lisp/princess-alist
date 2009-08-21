function filter(event)
{
  var e = event || window.event;
  var code = e.charCode || e.keyCode;

  if (code == 13)  // return key
    getTranslation();
}
