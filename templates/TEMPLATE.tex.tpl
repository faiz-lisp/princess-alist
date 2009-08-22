\documentclass[adobefonts]{ctexart}

\CTEXoptions[captiondelimiter={\quad}]

\usepackage{amsmath}            % AMS的数学宏包
\usepackage{amssymb}            % AMS的数学符号宏包
\usepackage{graphicx}           % 插入图片需要的宏包
\usepackage{float}              % 强大的浮动环境控制宏包
\usepackage{framed}             % `shaded'环境需要用到
\usepackage{enumitem}           % 增强列表功能

\usepackage{shortvrb}           % 简化\verb的写法
\MakeShortVerb{\|}

\usepackage{color}              % 可以定义各种颜色
\usepackage[x11names]{xcolor}   % 下面的RoyalBlue3颜色需要用到的宏包
% 自定义的几种颜色
\definecolor{shadecolor}{gray}{0.85}
% \definecolor{darkblue}{rgb}{52,101,164}
% \definecolor{darkgreen}{rgb}{78,154,6}

% % 设置背景颜色
% \definecolor{bisque}{rgb}{.996,.891,.755}
% \pagecolor{bisque}

\usepackage[pdfauthor={Dreamseeker},
            pdftitle={For Alist},
            colorlinks=true,
            urlcolor=blue,
            linkcolor=RoyalBlue3]{hyperref} % 为超链接设置颜色, 修改PDF文件信息

\title{\textbf{For Alist}}
\date{}
\author{Dreamseeker}

\usepackage[pagestyles]{titlesec} % 定制页眉页脚
% % 设置页眉页脚
% \newpagestyle{main}{%
%   \sethead[$\cdot$~\thepage~$\cdot$][][\thesection\quad%
%   \sectiontitle]{\thesection\quad\sectiontitle}{}{%
%   $\cdot$~\thepage~$\cdot$}
%   \setfoot{}{}{}\headrule}
% \pagestyle{main}
% \renewpagestyle{plain}{\sethead{}{}{}\setfoot{}{}{}}
\pagestyle{plain}

\usepackage[top=1in,bottom=1in,left=1.25in,right=1.25in]{geometry} % 设置页边距

\setlength{\belowcaptionskip}{1em} % 设置caption之后的距离

% XeTeX logo
\def\XeTeX{\leavevmode
\setbox0=\hbox{X\lower.5ex\hbox{\kern-.15em\reflectbox{E}}\kern-.1667em
\TeX}%
\dp0=0pt\ht0=0pt\box0}

\newcommand{\LaN}{L{\scriptsize\hspace{-0.47em}\raisebox{0.23em}{A}}\hspace{-0.1em}N}

\begin{document}

\maketitle

\tableofcontents
\newpage

\end{document}
