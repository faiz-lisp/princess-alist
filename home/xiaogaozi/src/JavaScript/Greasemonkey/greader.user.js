// ==UserScript==
// @name          Star Cutter for Google Reader
// @description
// @author        xiaogaozi
// @version       0.0.1
// @license       GPLv3
// @include       http://*google.tld/reader/view*
// @include       https://*google.tld/reader/view*
// ==/UserScript==

var mover = function() {
    this.style.backgroundColor = "white";
};

(function()
 {
     GM_xmlhttpRequest({
         method: "GET",

         /*
          * Get starred items, the value of 'n' represents how many items get.
          */
         url: "http://www.google.com/reader/atom/user/-/state/com.google/starred?n=100000",

         headers:
         {
             "User-Agent": "Mozilla/5.0",
             "Accept": "text/xml"
         },

         onload:
         function(response)
         {
             if (response.status == 200)
             {
                 if (!response.responseXML)
                     response.responseXML = new DOMParser().parseFromString(response.responseText, "text/xml");
                 var xml_content = response.responseXML;
                 var star_items = xml_content.getElementsByTagName("source");
                 var star_titles = {};

                 for (var i = 0; i != star_items.length; ++i)
                 {
                     var title = star_items[i].getElementsByTagName("title")[0].firstChild.nodeValue;

                     /*
                      * Store structure: { title: { "title": , "count": }, ... }
                      */
                     if (title in star_titles)
                     {
                         ++star_titles[title].count;
                     }
                     else
                     {
                         var node = {};
                         node.title = title;
                         node.count = 1;
                         star_titles[title] = node;
                     }
                 }

                 /*
                  * Insert starred items.
                  */
                 var star_div = document.getElementById("star-selector");
                 var items_list = document.createElement("ul");
                 items_list.style.clear = "both";
                 items_list.style.overflow = "auto";
                 items_list.style.position = "relative";
                 items_list.style.paddingLeft = "0";
                 items_list.style.margin = "0";
                 items_list.style.height = "80px";

                 for (var item in star_titles)
                 {
                     var title = item + " (" + star_titles[item].count + ")";

                     var l = document.createElement("li");
                     l.style.listStyleType = "none";
                     l.style.positon = "relative";
                     l.style.margin = "0";

                     var a = document.createElement("a");
                     a["href"] = "user/-/state/com.google/starred";
                     a["title"] = title;
                     a.style.display = "block";
                     a.style.position = "relative";
                     a.style.whiteSpace = "nowrap";

                     var s = document.createElement("span");
                     s.innerHTML = title;
                     s.onmouseover = mover;

                     a.appendChild(s);
                     l.appendChild(a);
                     items_list.appendChild(l);
                 }
                 star_div.appendChild(items_list);
             }
             else
                 alert("Greasemonkey: We will come back later from Mars.");
         }});
 })();
