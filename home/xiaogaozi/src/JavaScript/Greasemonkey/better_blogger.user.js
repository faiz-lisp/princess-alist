// ==UserScript==
// @name          Better Blogger
// @description   Enhance Blogger's experience.
// @author        Changjian Gao
// @version       0.0.1
// @license       GPLv3
// @include       http://*.blogger.com/*
// ==/UserScript==

function moreEditArea()
{
  var e;

  if (e = document.getElementById("modebar"))
    e.style.width = "100%";

  if (e = document.getElementById("editarea"))
    e.style.width = "100%";

  if (e = document.getElementById("textarea"))
    e.style.height = "450px";

  if (e = document.getElementById(""))
}

(function()
 {
   moreEditArea();
 })();
