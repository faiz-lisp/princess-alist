#!/usr/bin/perl -w

use strict;
use WWW::Mechanize;

sub xclip
{
  open(XCLIP, "|/usr/bin/xclip") or warn("No xclip - use .p\n"), return;
  print XCLIP $_[0];
  close XCLIP;
}

my $poster = "Dreamseeker";  # 张贴者
my $paste_url = 'http://paste.ubuntu.org.cn/';
my $screenshot = $ARGV[0];

my $mech = WWW::Mechanize->new();
$mech->get("$paste_url");
$mech->submit_form(
                    with_fields =>
                    {
                      "screenshot" => $screenshot,
                      "poster" => $poster
                    },
                    form_name => "editor",
                    button => "paste"
                  );

if ($mech->success())
{
  my $rr = $mech->uri();
  print($rr . "\n");
  xclip($rr);
  my $rrr = "贴图地址: " . $rr;
  `/home/xiaogaozi/Document/ShellScript/osd_prompt.sh '$rrr'`;  # 调用脚本用gnome-osd显示
}
else
{
  `/home/xiaogaozi/Document/ShellScript/osd_prompt.sh "贴图失败"`;  # 调用脚本用gnome-osd显示
  print "ERROR:\t" . $mech->status() . "\n";
}
