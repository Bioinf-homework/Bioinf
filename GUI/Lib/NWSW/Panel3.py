# coding=utf-8
#Boa:FramePanel:Panel3

import wx

import os

ddir = os.path.split(os.path.realpath(__file__))[0]

[wxID_PANEL3, wxID_PANEL3LOAD_BUTTON, wxID_PANEL3RADIOBOX, 
 wxID_PANEL3RESULT_TEXT, wxID_PANEL3START_BUTTON, wxID_PANEL3STATICBOX1, 
 wxID_PANEL3S_INPUT, wxID_PANEL3S_TEXT, wxID_PANEL3T_INPUT, wxID_PANEL3T_TEXT, 
] = [wx.NewId() for _init_ctrls in range(10)]

class Panel3(wx.Panel):
    def __init__(self, prnt):
        # generated method, don't edit
        wx.Panel.__init__(self, id=wxID_PANEL3, name='', parent=prnt,
              pos=wx.Point(223, 121), size=wx.Size(309, 351),
              style=wx.TAB_TRAVERSAL)
        self.SetClientSize(wx.Size(693, 612))

        self.s_text = wx.StaticText(id=wxID_PANEL3S_TEXT, label=u'S:',
              name=u's_text', parent=self, pos=wx.Point(56, 56),
              size=wx.Size(18, 22), style=0)
        self.s_text.SetFont(wx.Font(14, wx.SWISS, wx.NORMAL, wx.NORMAL, False,
              u'Arial'))

        self.t_text = wx.StaticText(id=wxID_PANEL3T_TEXT, label=u'T:',
              name=u't_text', parent=self, pos=wx.Point(56, 88),
              size=wx.Size(17, 22), style=0)
        self.t_text.SetFont(wx.Font(14, wx.SWISS, wx.NORMAL, wx.NORMAL, False,
              u'Arial'))

        self.s_input = wx.TextCtrl(id=wxID_PANEL3S_INPUT, name=u's_input',
              parent=self, pos=wx.Point(104, 56), size=wx.Size(264, 22),
              style=0, value=u'')
        self.s_input.SetFont(wx.Font(12, wx.SWISS, wx.NORMAL, wx.NORMAL, False,
              u''))

        self.t_input = wx.TextCtrl(id=wxID_PANEL3T_INPUT, name=u't_input',
              parent=self, pos=wx.Point(104, 88), size=wx.Size(264, 22),
              style=0, value=u'')

        self.load_button = wx.Button(id=wxID_PANEL3LOAD_BUTTON, label=u'Load',
              name=u'load_button', parent=self, pos=wx.Point(384, 56),
              size=wx.Size(75, 24), style=0)
        self.load_button.SetFont(wx.Font(12, wx.SWISS, wx.NORMAL, wx.NORMAL,
              False, u''))
        self.load_button.Bind(wx.EVT_BUTTON, self.load)

        self.start_button = wx.Button(id=wxID_PANEL3START_BUTTON,
              label=u'Start', name=u'start_button', parent=self,
              pos=wx.Point(384, 88), size=wx.Size(75, 24), style=0)
        self.start_button.SetFont(wx.Font(12, wx.SWISS, wx.NORMAL, wx.NORMAL,
              False, u''))
        self.start_button.Bind(wx.EVT_BUTTON, self.start)

        self.result_text = wx.TextCtrl(id=wxID_PANEL3RESULT_TEXT,
              name=u'result_text', parent=self, pos=wx.Point(72, 176),
              size=wx.Size(528, 360), style=wx.TE_MULTILINE | wx.HSCROLL,
              value=u'')

        self.staticBox1 = wx.StaticBox(id=wxID_PANEL3STATICBOX1,
              label=u'Result', name='staticBox1', parent=self, pos=wx.Point(56,
              152), size=wx.Size(568, 400), style=0)
        self.staticBox1.SetFont(wx.Font(12, wx.SWISS, wx.NORMAL, wx.NORMAL,
              False, u''))

        self.radioBox = wx.RadioBox(choices=['NW', 'SW'],
              id=wxID_PANEL3RADIOBOX, label=u'\u9009\u62e9\u7b97\u6cd5',
              majorDimension=1, name=u'radioBox', parent=self, pos=wx.Point(472,
              56), size=wx.Size(136, 64), style=wx.RA_SPECIFY_ROWS)
        self.radioBox.SetFont(wx.Font(14, wx.SWISS, wx.NORMAL, wx.NORMAL, False,
              u''))

    # def __init__(self, parent, id, pos, size, style, name):
    #     self._init_ctrls(parent)

    def load(self,event):
        # print self.radioBox.GetString(self.radioBox.GetSelection())
        fs = open(ddir+"/s.txt")
        s = fs.read()
        self.s_input.SetValue(s)

        f = open(ddir+"/t.txt")
        ts = f.read()
        self.t_input.SetValue(ts)
        pass

    def start(self,evt):
         with open(ddir+"/s.txt","w") as f:
              # pass
              data = self.s_input.GetValue()
              f.write(data)
         with open(ddir+"/t.txt","w") as f:
              # pass
              data = self.t_input.GetValue()
              f.write(data)
         with open(ddir+"/choice.txt","w") as f:
              data = self.radioBox.GetSelection()
              print data
              f.write(str(data+1))
         # fs = open(ddir+"/s.txt")
         os.popen(ddir+"/nwsw")
         f = open(ddir+"/result.txt")
         data = f.read()
         f = open(ddir+"/status.txt")
         data2 = f.read()
         f = open(ddir+"/path.txt")
         data3 = f.read()
         self.result_text.SetValue(data+"\n\n状态转移矩阵：\n"+data2+"\n路径：\n"+data3[:-2]+"\n\n\n")
         pass

class DemoFrame(wx.Frame):
    def __init__(self):
        wx.Frame.__init__(self, None, wx.ID_ANY, "Panel Tutorial")
        panel = Panel3(self)
        self.Show()


# ----------------------------------------------------------------------
if __name__ == "__main__":
    app = wx.PySimpleApp()
    frame = DemoFrame()
    app.MainLoop()