#!/usr/bin/env python
# -*- coding: gbk -*-

# A debate timer. <https://github.com/xiaogaozi/princess-alist>
# Copyright (C) 2010  xiaogaozi <gaochangjian@gmail.com>
# 
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

import wx
import os
import time
import winsound
import threading

ID_EXIT = 0
ID_ABOUT = 1
ID_TIME_BUTTON1 = 10
ID_TIME_BUTTON2 = 11
ID_TIME_BUTTON3 = 6121
ID_STAGE_BUTTON1 = 12
ID_STAGE_BUTTON2 = 13
ID_STAGE_BUTTON3 = 14
ID_STAGE_BUTTON4 = 15
ID_STAGE_BUTTON5 = 16
ID_ALIST_BUTTON1 = 612
ID_ALIST_BUTTON2 = 121

class MainWindow(wx.Frame):
    # Use to store running thread.
    thread_map = {}
    # Initial value of timer.
    initial_minute = 2
    initial_second = 59

    def __init__(self):
        wx.Frame.__init__(self, None, wx.ID_ANY, "Dr. Timer",
                          size = wx.Size(1024, 768))
        self.panel = wx.Panel(self, wx.ID_ANY)

        # Add menu.
        filemenu = wx.Menu()
        filemenu.Append(ID_EXIT, "&Exit")
        helpmenu = wx.Menu()
        helpmenu.Append(ID_ABOUT, "&About")
        menuBar = wx.MenuBar()
        menuBar.Append(filemenu, "&File")
        menuBar.Append(helpmenu, "&Help")
        self.SetMenuBar(menuBar)
        wx.EVT_MENU(self, ID_EXIT, self.OnExit)
        wx.EVT_MENU(self, ID_ABOUT, self.OnAbout)

        # Display title.
        self.displayTitle()

        # Display current stage.
        self.displayCurrentStage()

        # Display positive side and negative side.
        self.displayTwoSide()

        # Display timer.
        self.displayTimer()

        # Display players.
        self.displayPlayer()

        # Display issue.
        self.displayIssue()

        # Display time button.
        self.displayTimeButton()

        # Display stages switch button.
        self.displayStageButton()

        # Display author.
        self.displayAuthor()

        self.sizer = wx.BoxSizer(wx.VERTICAL)
        self.sizer.Add(self.title, 0,
                       wx.ALIGN_CENTER_HORIZONTAL | wx.TOP, 52)
        self.sizer.Add(self.sizer1, 0,
                       wx.ALIGN_CENTER_HORIZONTAL | wx.TOP | wx.BOTTOM, 10)
        self.sizer.Add(self.sizer2, 0,
                       wx.ALIGN_CENTER_HORIZONTAL | wx.BOTTOM, 10)
        self.sizer.Add(self.sizer3, 0,
                       wx.ALIGN_CENTER_HORIZONTAL | wx.BOTTOM, 10)
        self.sizer.Add(self.sizer4, 0,
                       wx.ALIGN_CENTER_HORIZONTAL | wx.BOTTOM, 10)
        self.sizer.Add(self.sizer5, 0,
                       wx.ALIGN_CENTER_HORIZONTAL | wx.BOTTOM, 10)
        self.sizer.Add(self.sizer6, 0,
                       wx.ALIGN_CENTER_HORIZONTAL | wx.BOTTOM, 10)
        self.sizer.Add(self.sizer7, 0,
                       wx.ALIGN_CENTER_HORIZONTAL | wx.BOTTOM, 10)
        self.sizer.Add(self.author, 0,
                       wx.ALIGN_CENTER_HORIZONTAL | wx.LEFT, 750)

        self.panel.SetSizer(self.sizer)

        # Some trickery :)
        self.sizer.Layout()
        self.SetSize(wx.Size(801, 601))

        # Centre the frame on the display.
        self.Centre()

    def OnAbout(self, e):
        """About dialog."""
        d = wx.MessageDialog(self,
                             "xiaogaozi <gaochangjian@gmail.com> & LaN Present, Copyright 2010\n\nPowerd by Python & wxPython",
                             "About", wx.OK)
        d.ShowModal()
        d.Destroy()

    def OnExit(self, e):
        """Goodbye."""
        self.Close(True)

    def displayTitle(self):
        """Display title."""
        self.title = wx.StaticText(self.panel, wx.ID_ANY, "2010成都信息工程学院社团辩论赛")
        self.title.SetFont(wx.Font(42, wx.FONTFAMILY_DEFAULT,
                                   wx.FONTSTYLE_NORMAL, wx.FONTWEIGHT_BOLD))

    def displayCurrentStage(self):
        """Display current stage."""
        self.head = wx.StaticText(self.panel, wx.ID_ANY, "当前环节：")
        self.head.SetFont(wx.Font(30, wx.FONTFAMILY_DEFAULT,
                                  wx.FONTSTYLE_NORMAL, wx.FONTWEIGHT_BOLD))
        self.cur_stage = wx.StaticText(self.panel, wx.ID_ANY, "立论")
        self.cur_stage.SetFont(wx.Font(30, wx.FONTFAMILY_DEFAULT,
                                       wx.FONTSTYLE_NORMAL, wx.FONTWEIGHT_BOLD))
        self.cur_stage.SetForegroundColour("RED")
        self.sizer1 = wx.BoxSizer(wx.HORIZONTAL)
        self.sizer1.Add(self.head, 0)
        self.sizer1.Add(self.cur_stage, 0)

    def displayTwoSide(self):
        """Display positive side and negative side."""
        self.positive = wx.StaticText(self.panel, wx.ID_ANY, "正方")
        self.positive.SetFont(wx.Font(30, wx.FONTFAMILY_DEFAULT,
                                      wx.FONTSTYLE_NORMAL, wx.FONTWEIGHT_NORMAL))
        self.negative = wx.StaticText(self.panel, wx.ID_ANY, "反方")
        self.negative.SetFont(wx.Font(30, wx.FONTFAMILY_DEFAULT,
                                      wx.FONTSTYLE_NORMAL, wx.FONTWEIGHT_NORMAL))
        self.sizer2 = wx.BoxSizer(wx.HORIZONTAL)
        self.sizer2.Add(self.positive, 0, wx.LEFT | wx.RIGHT, 230)
        self.sizer2.Add(self.negative, 0, wx.LEFT | wx.RIGHT, 230)

    def displayTimer(self):
        """Display timer."""
        self.pos_timer = wx.StaticText(self.panel, wx.ID_ANY, "03:00")
        self.pos_timer.SetFont(wx.Font(100, wx.FONTFAMILY_DEFAULT,
                                       wx.FONTSTYLE_NORMAL, wx.FONTWEIGHT_BOLD))
        self.pos_timer.SetForegroundColour("BLUE")
        self.neg_timer = wx.StaticText(self.panel, wx.ID_ANY, "03:00")
        self.neg_timer.SetFont(wx.Font(100, wx.FONTFAMILY_DEFAULT,
                                       wx.FONTSTYLE_NORMAL, wx.FONTWEIGHT_BOLD))
        self.neg_timer.SetForegroundColour("BLUE")

        # Just during 'cross-question' stage, this timer will be shown.
        self.alist_timer = wx.StaticText(self.panel, wx.ID_ANY, "00:10")
        self.alist_timer.SetFont(wx.Font(35, wx.FONTFAMILY_DEFAULT,
                                         wx.FONTSTYLE_NORMAL,
                                         wx.FONTWEIGHT_BOLD))
        self.alist_timer.SetForegroundColour("FOREST GREEN")
        self.alist_button1 = wx.Button(self.panel, ID_ALIST_BUTTON1,
                                       "提问(&C)", size = wx.Size(70, 30))
        self.alist_button1.SetFont(wx.Font(10, wx.FONTFAMILY_DEFAULT,
                                           wx.FONTSTYLE_NORMAL,
                                           wx.FONTWEIGHT_NORMAL))
        self.alist_button2 = wx.Button(self.panel, ID_ALIST_BUTTON2,
                                       "回答(&V)", size = wx.Size(70, 30))
        self.alist_button2.SetFont(wx.Font(10, wx.FONTFAMILY_DEFAULT,
                                           wx.FONTSTYLE_NORMAL,
                                           wx.FONTWEIGHT_NORMAL))
        self.alist_button2.Disable()
        self.alist_sizer1 = wx.BoxSizer(wx.VERTICAL)
        self.alist_sizer2 = wx.BoxSizer(wx.HORIZONTAL)
        self.alist_sizer2.Add(self.alist_button1, 0)
        self.alist_sizer2.Add(self.alist_button2, 0)
        self.alist_sizer1.Add(self.alist_timer, 0,
                              wx.ALIGN_CENTER_HORIZONTAL | wx.TOP, 45)
        self.alist_sizer1.Add(self.alist_sizer2, 0)
        wx.EVT_BUTTON(self, ID_ALIST_BUTTON1, self.forAlist)
        wx.EVT_BUTTON(self, ID_ALIST_BUTTON2, self.forAlist)

        self.sizer3 = wx.BoxSizer(wx.HORIZONTAL)
        self.sizer3.Add(self.pos_timer, 0, wx.RIGHT, 80)
        self.sizer3.AddStretchSpacer()
        self.sizer3.Add(self.alist_sizer1, 0)
        self.sizer3.AddStretchSpacer()
        self.sizer3.Add(self.neg_timer, 0, wx.LEFT, 80)
        self.sizer3.Hide(self.alist_sizer1)
        self.sizer3.Layout()

    def forAlist(self, e):
        """Display time during Q&A."""
        # Button's label.
        l = e.GetEventObject().GetLabel().encode('gbk')

        if l == "提问(&C)":
            self.alist_button1.SetLabel("停止(&C)")
            self.a1 = self.createTimeThread(0, 9, self.alist_timer,
                                            self.alist_button1, l, "a1")
        elif l == "回答(&V)":
            self.alist_button2.SetLabel("停止(&V)")
            self.a2 = self.createTimeThread(0, 19, self.alist_timer,
                                            self.alist_button2, l, "a2")
        elif l == "停止(&C)":
            self.a1.flag = 2
            # Erase this thread's record.
            self.deleteThreadRecord("a1")
            # Set some value.
            self.alist_timer.SetLabel("00:20")
            self.alist_button1.SetLabel("提问(&C)")
            self.alist_button1.Disable()
            self.alist_button2.Enable()
        elif l == "停止(&V)":
            self.a2.flag = 2
            # Erase this thread's record.
            self.deleteThreadRecord("a2")
            # Set some value.
            self.alist_timer.SetLabel("00:10")
            self.alist_button2.SetLabel("回答(&V)")
            self.alist_button2.Disable()
            self.alist_button1.Enable()

    def displayPlayer(self):
        """Display players."""
        self.p1 = wx.TextCtrl(self.panel, wx.ID_ANY, "参赛者",
                              size = wx.Size(490, 40), style = wx.TE_CENTER)
        self.p1.SetFont(wx.Font(20, wx.FONTFAMILY_DEFAULT,
                                wx.FONTSTYLE_NORMAL, wx.FONTWEIGHT_NORMAL))
        self.p2 = wx.TextCtrl(self.panel, wx.ID_ANY, "参赛者",
                              size = wx.Size(490, 40), style = wx.TE_CENTER)
        self.p2.SetFont(wx.Font(20, wx.FONTFAMILY_DEFAULT,
                                wx.FONTSTYLE_NORMAL, wx.FONTWEIGHT_NORMAL))
        self.sizer4 = wx.BoxSizer(wx.HORIZONTAL)
        self.sizer4.Add(self.p1, 0, wx.RIGHT, 20)
        self.sizer4.Add(self.p2, 0, wx.LEFT, 20)

    def displayIssue(self):
        """Display issue."""
        self.i1 = wx.TextCtrl(self.panel, wx.ID_ANY, "正方观点",
                              size = wx.Size(490, 80), style = wx.TE_MULTILINE)
        self.i1.SetFont(wx.Font(20, wx.FONTFAMILY_DEFAULT,
                                wx.FONTSTYLE_NORMAL, wx.FONTWEIGHT_NORMAL))
        self.i2 = wx.TextCtrl(self.panel, wx.ID_ANY, "反方观点",
                              size = wx.Size(490, 80), style = wx.TE_MULTILINE)
        self.i2.SetFont(wx.Font(20, wx.FONTFAMILY_DEFAULT,
                                wx.FONTSTYLE_NORMAL, wx.FONTWEIGHT_NORMAL))
        self.sizer5 = wx.BoxSizer(wx.HORIZONTAL)
        self.sizer5.Add(self.i1, 0, wx.RIGHT, 20)
        self.sizer5.Add(self.i2, 0, wx.LEFT, 20)

    def displayTimeButton(self):
        """Display time button."""
        self.time_button1 = wx.Button(self.panel, ID_TIME_BUTTON1,
                                      "开始计时(&A)", size = wx.Size(160, 50))
        self.time_button1.SetFont(wx.Font(20, wx.FONTFAMILY_DEFAULT,
                                          wx.FONTSTYLE_NORMAL,
                                          wx.FONTWEIGHT_NORMAL))
        self.time_button2 = wx.Button(self.panel, ID_TIME_BUTTON2,
                                      "开始计时(&D)", size = wx.Size(160, 50))
        self.time_button2.SetFont(wx.Font(20, wx.FONTFAMILY_DEFAULT,
                                          wx.FONTSTYLE_NORMAL,
                                          wx.FONTWEIGHT_NORMAL))

        # This button only display during 'free debate' stage.
        self.time_button3 = wx.Button(self.panel, ID_TIME_BUTTON3,
                                      "开始计时(&G)", size = wx.Size(160, 50))
        self.time_button3.SetFont(wx.Font(20, wx.FONTFAMILY_DEFAULT,
                                          wx.FONTSTYLE_NORMAL,
                                          wx.FONTWEIGHT_NORMAL))

        self.sizer6 = wx.BoxSizer(wx.HORIZONTAL)
        self.sizer6.Add(self.time_button1, 0, wx.RIGHT, 195)
        self.sizer6.Add(self.time_button2, 0, wx.LEFT, 195)
        self.sizer6.Add(self.time_button3, 0, wx.LEFT | wx.RIGHT, 275)
        self.sizer6.Hide(self.time_button3)

        # Call this to force layout of the children anew.
        self.sizer6.Layout()

        wx.EVT_BUTTON(self, ID_TIME_BUTTON1, self.startOrPause)
        wx.EVT_BUTTON(self, ID_TIME_BUTTON2, self.startOrPause)
        wx.EVT_BUTTON(self, ID_TIME_BUTTON3, self.freeDebate)

    def startOrPause(self, e):
        """Start or pause time."""
        # Button's label.
        l = e.GetEventObject().GetLabel().encode('gbk')

        if l == "开始计时(&A)":
            self.time_button1.SetLabel("暂停计时(&S)")
            self.time_button2.Disable()

            if "t1" in self.thread_map:
                self.t1.flag = 0
                # Wake up this thread.
                self.t1.event.set()
            else:
                self.t1 = self.createTimeThread(self.initial_minute, self.initial_second,
                                                self.pos_timer, self.time_button1,
                                                l, "t1")
        elif l == "暂停计时(&S)":
            self.t1.flag = 1
            self.time_button1.SetLabel("开始计时(&A)")

            # If another thread haven't ended, enable its start button.
            if self.neg_timer.GetLabel() != "00:00":
                self.time_button2.Enable()
        elif l == "开始计时(&D)":
            # print self.t1.isAlive()
            # return

            self.time_button2.SetLabel("暂停计时(&F)")
            self.time_button1.Disable()

            if "t2" in self.thread_map:
                self.t2.flag = 0
                # Wake up this thread.
                self.t2.event.set()
            else:
                self.t2 = self.createTimeThread(self.initial_minute, self.initial_second,
                                                self.neg_timer, self.time_button2,
                                                l, "t2")
        elif l == "暂停计时(&F)":
            self.t2.flag = 1
            self.time_button2.SetLabel("开始计时(&D)")

            # If another thread haven't ended, enable its start button.
            if self.pos_timer.GetLabel() != "00:00":
                self.time_button1.Enable()

    def freeDebate(self, e):
        """Start free debate."""
        # Button's label.
        l = e.GetEventObject().GetLabel().encode('gbk')

        if l == "开始计时(&G)":
            self.time_button3.SetLabel("=> (&G)")
            self.f1 = self.createTimeThread(self.initial_minute, self.initial_second,
                                            self.pos_timer, self.time_button3,
                                            l, "f1")
        elif l == "=> (&G)":
            if self.f1.isAlive():
                self.time_button3.SetLabel("<= (&G)")
                self.f1.flag = 1
            else:
                self.time_button3.SetLabel("开始计时(&G)")
                self.time_button3.Disable()

            if "f2" in self.thread_map:
                self.f2.flag = 0
                # Wake up this thread.
                self.f2.event.set()
            else:
                self.f2 = self.createTimeThread(self.initial_minute, self.initial_second,
                                                self.neg_timer, self.time_button3,
                                                l, "f2")
        elif l == "<= (&G)":
            if self.f2.isAlive():
                self.time_button3.SetLabel("=> (&G)")
                self.f2.flag = 1
            else:
                self.time_button3.SetLabel("开始计时(&G)")
                self.time_button3.Disable()

            if "f1" in self.thread_map:
                self.f1.flag = 0
                # Wake up this thread.
                self.f1.event.set()
            else:
                self.f1 = self.createTimeThread(self.initial_minute, self.initial_second,
                                                self.pos_timer, self.time_button3,
                                                l, "f1")

    def displayStageButton(self):
        """Display stages switch button."""
        self.s_button1 = wx.Button(self.panel, ID_STAGE_BUTTON1,
                                   "立论(&Q)", size = wx.Size(130, 40))
        self.s_button2 = wx.Button(self.panel, ID_STAGE_BUTTON2,
                                   "论证辩驳(&W)", size = wx.Size(130, 40))
        self.s_button3 = wx.Button(self.panel, ID_STAGE_BUTTON3,
                                   "盘问(&E)", size = wx.Size(130, 40))
        self.s_button4 = wx.Button(self.panel, ID_STAGE_BUTTON4,
                                   "自由辩论(&R)", size = wx.Size(130, 40))
        self.s_button5 = wx.Button(self.panel, ID_STAGE_BUTTON5,
                                   "总结陈词(&T)", size = wx.Size(130, 40))
        self.s_button1.SetFont(wx.Font(15, wx.FONTFAMILY_DEFAULT,
                                       wx.FONTSTYLE_NORMAL,
                                       wx.FONTWEIGHT_NORMAL))
        self.s_button2.SetFont(wx.Font(15, wx.FONTFAMILY_DEFAULT,
                                       wx.FONTSTYLE_NORMAL,
                                       wx.FONTWEIGHT_NORMAL))
        self.s_button3.SetFont(wx.Font(15, wx.FONTFAMILY_DEFAULT,
                                       wx.FONTSTYLE_NORMAL,
                                       wx.FONTWEIGHT_NORMAL))
        self.s_button4.SetFont(wx.Font(15, wx.FONTFAMILY_DEFAULT,
                                       wx.FONTSTYLE_NORMAL,
                                       wx.FONTWEIGHT_NORMAL))
        self.s_button5.SetFont(wx.Font(15, wx.FONTFAMILY_DEFAULT,
                                       wx.FONTSTYLE_NORMAL,
                                       wx.FONTWEIGHT_NORMAL))
        self.sizer7 = wx.BoxSizer(wx.HORIZONTAL)
        self.sizer7.Add(self.s_button1, 0)
        self.sizer7.Add(self.s_button2, 0, wx.LEFT, 20)
        self.sizer7.Add(self.s_button3, 0, wx.LEFT, 20)
        self.sizer7.Add(self.s_button4, 0, wx.LEFT, 20)
        self.sizer7.Add(self.s_button5, 0, wx.LEFT, 20)
        wx.EVT_BUTTON(self, ID_STAGE_BUTTON1, self.changeStage)
        wx.EVT_BUTTON(self, ID_STAGE_BUTTON2, self.changeStage)
        wx.EVT_BUTTON(self, ID_STAGE_BUTTON3, self.changeStage)
        wx.EVT_BUTTON(self, ID_STAGE_BUTTON4, self.changeStage)
        wx.EVT_BUTTON(self, ID_STAGE_BUTTON5, self.changeStage)

    def changeStage(self, e):
        """Change stage and initialize time."""
        # Stop all of running threads.
        for t in self.thread_map:
            thread = self.thread_map[t]
            thread.flag = 2

            # # If this thread is waiting, wake up it.
            # if thread.event.isSet() == False:
            #     thread.event.set()

            # # Main process waits for thread end.
            # while thread.isAlive():
            #     print "join", t
            #     thread.join(0.2)
        # Clear threads' record.
        self.thread_map.clear()

        # Button's ID.
        id = e.GetId()

        # Initialize all values, such as button's label,
        # timer's number, button's state (enable or disable,
        # show or hide), and initial minute and second.
        if id == ID_STAGE_BUTTON1:
            self.cur_stage.SetLabel("立论")
            self.pos_timer.SetLabel("03:00")
            self.neg_timer.SetLabel("03:00")
            self.initial_minute = 2
            self.initial_second = 59
        elif id == ID_STAGE_BUTTON2:
            self.cur_stage.SetLabel("论证辩驳")
            self.pos_timer.SetLabel("01:30")
            self.neg_timer.SetLabel("01:30")
            self.initial_minute = 1
            self.initial_second = 29
        elif id == ID_STAGE_BUTTON3:
            self.cur_stage.SetLabel("盘问")
            self.pos_timer.SetLabel("02:00")
            self.neg_timer.SetLabel("02:00")
            self.initial_minute = 1
            self.initial_second = 59

            # Show this little timer.
            self.sizer3.Show(self.alist_sizer1)
            self.sizer3.Layout()
            self.alist_timer.SetLabel("00:10")
            self.alist_button1.SetLabel("提问(&C)")
            self.alist_button2.SetLabel("回答(&V)")
            self.alist_button1.Enable()
            self.alist_button2.Disable()

            self.sizer6.Hide(self.time_button3)
            self.sizer6.Show(self.time_button1)
            self.sizer6.Show(self.time_button2)
            self.sizer6.Layout()
            
            self.time_button1.SetLabel("开始计时(&A)")
            self.time_button2.SetLabel("开始计时(&D)")
            self.time_button1.Enable()
            self.time_button2.Enable()
            return
        elif id == ID_STAGE_BUTTON4:
            self.cur_stage.SetLabel("自由辩论")
            self.pos_timer.SetLabel("06:00")
            self.neg_timer.SetLabel("06:00")
            self.initial_minute = 5
            self.initial_second = 59

            self.sizer3.Hide(self.alist_sizer1)
            self.sizer3.Layout()

            self.sizer6.Show(self.time_button3)
            self.sizer6.Hide(self.time_button1)
            self.sizer6.Hide(self.time_button2)
            self.sizer6.Layout()

            self.time_button3.SetLabel("开始计时(&G)")
            self.time_button3.Enable()
            return
        elif id == ID_STAGE_BUTTON5:
            self.cur_stage.SetLabel("总结陈词")
            self.pos_timer.SetLabel("03:00")
            self.neg_timer.SetLabel("03:00")
            self.initial_minute = 2
            self.initial_second = 59

        self.sizer3.Hide(self.alist_sizer1)
        self.sizer3.Layout()

        self.sizer6.Hide(self.time_button3)
        self.sizer6.Show(self.time_button1)
        self.sizer6.Show(self.time_button2)
        self.sizer6.Layout()
        
        self.time_button1.SetLabel("开始计时(&A)")
        self.time_button2.SetLabel("开始计时(&D)")
        self.time_button1.Enable()
        self.time_button2.Enable()

    def displayAuthor(self):
        """Display author."""
        self.author = wx.StaticText(self.panel, wx.ID_ANY, "by 软件工程学院")
        self.author.SetFont(wx.Font(20, wx.FONTFAMILY_DEFAULT,
                                    wx.FONTSTYLE_NORMAL, wx.FONTWEIGHT_NORMAL))

    def deleteThreadRecord(self, thread_name):
        """Erase specific thread's record."""
        del self.thread_map[thread_name]

    def createTimeThread(self, m, s, t, b, l, t_name):
        """Create a new TimeThread object.
        
        Parameter:
            m      - timer's initial minute
            s      - timer's initial second
            t      - timer
            b      - button
            l      - button's label
            t_name - thread's name"""
        # Construct a new thread.
        t = TimeThread(self, m, s, t, b, l, t_name)
        # Record this thread's state.
        self.thread_map[t_name] = t
        # Exit this thread when main process exits.
        t.daemon = True
        # Thread start.
        t.start()

        return t

    def play(self, filename):
        """Play sound."""
        winsound.PlaySound(filename, winsound.SND_FILENAME)

class TimeThread(threading.Thread):
    """You will like this fucking thread class :)"""
    def __init__(self, w, m, s, t, b, l, t_name):
        """Initialization.
        Look at 'createTimeThread()' function to
        know the meaning of parameters."""
        threading.Thread.__init__(self)

        # flag: 0 - thread be awakened
        #       1 - thread wait
        #       2 - thread end
        self.flag = 0

        self.w = w
        self.initial_minute = m
        self.initial_second = s
        self.timer = t
        self.button = b
        self.button_label = l
        self.thread_name = t_name

    def run(self):
        """Override function."""
        self.changeTime()

        # flag: 2 - thread end
        if self.flag == 2:
            return

        # t = "%02d:%02d" % (self.initial_minute + self.initial_second / 59,
        #                    (self.initial_second + 1) % 60)
        # self.timer.SetLabel(t)

        self.w.deleteThreadRecord(self.thread_name)
        self.flag = 0

        # This situation is during 'free debate' stage,
        # when positive side's time has over, but 
        # negative side doesn't, then let it continue.
        if self.thread_name == "f1" and "f2" in self.w.thread_map:
            self.button.SetLabel("=> (&G)")
        # This is similar situation.
        elif self.thread_name == "f2" and "f1" in self.w.thread_map:
            self.button.SetLabel("<= (&G)")
        # And this is also during 'free debate' stage.
        # It likes first situation, except negative side doesn't running.
        elif self.thread_name == "f1" and self.w.neg_timer.GetLabel() != "00:00":
            pass
        # Yep, you are still in the 'free debate' stage.
        # This is described as negative side and positive side
        # all end.
        elif self.thread_name == "f2" and (not "f1" in self.w.thread_map):
            self.button.SetLabel("开始计时(&G)")
            self.button.Disable()
        # Positive side end, and negative doesn't running.
        elif self.thread_name == "t1" and self.w.neg_timer.GetLabel() != "00:00":
            self.w.time_button2.Enable()
            self.button.SetLabel(self.button_label)
            self.button.Disable()
        # Negative side end, and positive doesn't running.
        elif self.thread_name == "t2" and self.w.pos_timer.GetLabel() != "00:00":
            self.w.time_button1.Enable()
            self.button.SetLabel(self.button_label)
            self.button.Disable()
        # Question end.
        elif self.thread_name == "a1":
            self.w.alist_button2.Enable()
            self.button.SetLabel(self.button_label)
            self.button.Disable()
            self.timer.SetLabel("00:20")
        # Answer end.
        elif self.thread_name == "a2":
            self.w.alist_button1.Enable(True)
            self.button.SetLabel(self.button_label)
            self.button.Disable()
            self.timer.SetLabel("00:10")
        # Others.
        else:
            self.button.SetLabel(self.button_label)
            self.button.Disable()

    def changeTime(self):
        """Change time of timer."""
        for i in range(self.initial_minute, -1, -1):
            for j in range(self.initial_second, -1, -1):
                # flag: 1 - thread wait
                #       2 - thread end
                if self.flag == 1:
                    self.event = threading.Event()
                    self.event.wait()
                elif self.flag == 2:
                    break;
                t = "%02d:%02d" % (i, j)
                self.timer.SetLabel(t)

                # Play warning sound.
                if self.w.cur_stage.GetLabel().encode('gbk') != "盘问":
                    if i == 0 and j == 30:
                        t = SoundThread(os.path.join("sound", "ring.wav"))
                        t.daemon = True
                        t.start()

                # Don't sleep when at the last loop.
                if i != 0 or j != 0:
                    time.sleep(1)

            # flag: 2 - thread end
            if self.flag == 2:
                break;

            # Make initial second begin with 59.
            if self.initial_second != 59:
                self.initial_second = 59

            # Play end sound.
            if i == 0 and j == 0:
                if self.thread_name == "a1" or self.thread_name == "a2":
                    t = SoundThread(os.path.join("sound", "ring.wav"))
                    t.daemon = True
                    t.start()
                else:
                    t = SoundThread(os.path.join("sound", "end.wav"))
                    t.daemon = True
                    t.start()

class SoundThread(threading.Thread):
    """Play sound."""
    def __init__(self, filename):
        threading.Thread.__init__(self)
        self.filename = filename

    def run(self):
        winsound.PlaySound(self.filename, winsound.SND_FILENAME)

if __name__ == "__main__":
    app = wx.PySimpleApp()
    frame = MainWindow()
    frame.Show()
    app.MainLoop()
