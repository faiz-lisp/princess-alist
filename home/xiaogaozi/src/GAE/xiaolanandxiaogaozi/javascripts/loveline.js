google.load("visualization", "1", { packages: ['annotatedtimeline'] });
google.setOnLoadCallback(drawLoveLine);

function drawLoveLine()
{
    var data = new google.visualization.DataTable();
    data.addColumn('date', 'Date');
    data.addColumn('number', 'Love\'s Memory');
    data.addColumn('string', 'title');
    data.addColumn('string', 'text');
    data.addRows(followOurLove());

    var options = {
        allowHtml: true,
        displayAnnotations: true,
        displayAnnotationsFilter: true
    };

    var chart = new google.visualization.AnnotatedTimeLine(document.getElementById("love_line"));
    chart.draw(data, options);
}

function followOurLove()
{
    var love_events = new Array();
    var i = 0;
    var year;
    var month;
    var day;
    var special_days = {
        L2007_11_14: [ 15000, '我的小纸条', '我默默地告诫自己: 勇敢一点. 今天, 我认识了你.' ],
        L2007_11_23: [ 8000, '秘密', '我在日记里写下关于你的秘密, 或许你不曾发觉.' ],
        L2007_12_1: [ 20000, '你是我的女朋友!', '单纯的一天, 记满了甜蜜与快乐.' ],
        L2007_12_10: [ 10000, '乒乓球', '这是你唯一可以称得上爱好的运动, 今天我们在一起玩得很愉快, 还认识了龙姐姐, :)' ],
        L2007_12_12: [ 9000, '短信', '那时的我们就这样每天通过几条短信互相诉说着.' ],
        L2007_12_20: [ 11000, '转筒', '两个小人努力地在上面踩啊踩, 你说你的心愿, 我说我的理想.' ],
        L2008_2_2: [ 13886, 'hashCode', '-1156203886' ],
        L2008_2_14: [ 13500, 'Valentine\'s Day', '还记得我送给你的《情书》吗?' ],
        L2008_2_23: [ 13000, '灯光与球场', '一起坐在高高的栏杆上, 吃着美味的零食.' ],
        L2008_3_5: [ 12000, '花匠', '你送给我一个小小的美丽盆栽.' ],
        L2008_3_9: [ 10000, 'Day 100', '多么神奇的100个日子.' ],
        L2008_4_10: [ 11000, '为你写日记', '今天我为你写了一篇日记, 那时的你总爱吃蛋黄派.' ],
        L2008_5_12: [ 13000, '地震', '即使再大的灾难, 我们也能一起度过.' ],
        L2008_6_12: [ 18000, 'FK', 'FK = Fist Kiss' ],
        L2008_6_24: [ 9500, '果冻', '某人的<a href="http://www.yupoo.com/photos/view?id=ff8080811aa55ef8011ab9131c896a46">爱心果冻</a>' ],
        L2008_9_6: [ 16121, '珍惜', '再次在心中默念: 珍惜身边的人.' ],
        L2008_10_1: [ 12500, '国色天香', '愉快的出游' ],
        L2008_10_26: [ 8900, 'Love\'s Secret', 'E3-Mi A1-La G3-Sol' ],
        L2009_1_1: [ 15000, '可爱的厨师', '什么时候能再吃到诱人的煎蛋呢?' ],
        L2009_1_26: [ 10000, '你是我的太阳', '又是新的一年, 你给了我最美好的新年祝福.' ],
        L2009_7_10: [ 9999, '欢乐谷', '玩得无比畅快~' ],
        L2009_10_2: [ 11000, '西岭雪山', '爬山爬到脚抽筋, XD' ],
        L2009_11_14: [ 15000, 'Cheer的演唱会', '终于带你看了一场老师的演唱会.' ],
        L2009_12_1: [ 20000, '2 Years', '亲爱的, 有你陪着真好.' ],
        L2009_12_31: [ 18000, '跨年K, :)' ],
        L2010_2_24: [ 15000, '滑雪真爽啊~' ]
    };

    for (year = 2007; year != 2011; ++year)
        for (month = 0; month != 12; ++month)
        {
            /*
             * Ending of date.
             */
            if (year == 2010 && month > 2)
                break;

            var max_day_of_month = getMaxDayOfMonth(year, month);
            for (day = 1; day != max_day_of_month + 1; ++day)
            {
                /*
                 * Set beginning of date.
                 */
                if (year < 2007 ||
                    year == 2007 && month < 10 ||
                    year == 2007 && month == 10 && day < 12)
                    continue;

                var ymd = "L" + year + "_" + (month + 1) + "_" + day;
                if (ymd in special_days)
                    love_events[i] = [
                        new Date(year, month, day),
                        special_days[ymd][0],
                        special_days[ymd][1],
                        special_days[ymd][2]
                    ];
                else
                    love_events[i] = [ new Date(year, month, day), 6121, undefined, undefined ];

                ++i;
            }
        }

    return love_events;
}

function getMaxDayOfMonth(year, month)
{
    var max_day_of_month;
    if (month == 0 || month == 2 || month == 4 || month == 6 ||
        month == 7 || month == 9 || month == 11)
        max_day_of_month = 31;
    else if (month == 3 || month == 5 || month == 8 || month == 10)
        max_day_of_month = 30;
    else
    {
        if ((year % 4 == 0 && year % 100 != 0) ||
            (year % 400 == 0))
            max_day_of_month = 29;
        else
            max_day_of_month = 28;
    }
    return max_day_of_month;
}
