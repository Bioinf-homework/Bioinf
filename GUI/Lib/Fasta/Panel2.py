# Boa:FramePanel:Panel2

import wx

[wxID_PANEL2, wxID_PANEL2LOAD_BUTTON, wxID_PANEL2START_BUTTON,
 wxID_PANEL2STATICBOX1, wxID_PANEL2STATICTEXT1, wxID_PANEL2STATICTEXT2,
 wxID_PANEL2STATICTEXT3, wxID_PANEL2S_INPUT, wxID_PANEL2S_TEXT,
 wxID_PANEL2TEXTCTRL1, wxID_PANEL2TEXTCTRL2, wxID_PANEL2T_INPUT,
 ] = [wx.NewId() for _init_ctrls in range(12)]

import os

ddir = os.path.split(os.path.realpath(__file__))[0]

class Panel2(wx.Panel):
    def __init__(self, prnt):
        # generated method, don't edit
        wx.Panel.__init__(self, id=wxID_PANEL2, name='', parent=prnt,
                          pos=wx.Point(383, 53), size=wx.Size(660, 625),
                          style=wx.TAB_TRAVERSAL)
        self.SetClientSize(wx.Size(644, 586))

        self.s_text = wx.StaticText(id=wxID_PANEL2S_TEXT, label=u'S:',
                                    name=u's_text', parent=self, pos=wx.Point(40, 40),
                                    size=wx.Size(18, 22), style=0)
        self.s_text.SetFont(wx.Font(14, wx.SWISS, wx.NORMAL, wx.NORMAL, False,
                                    u'Arial'))

        self.s_input = wx.TextCtrl(id=wxID_PANEL2S_INPUT, name=u's_input',
                                   parent=self, pos=wx.Point(80, 40), size=wx.Size(328, 26), style=0,
                                   value=u'')
        self.s_input.SetFont(wx.Font(14, wx.SWISS, wx.NORMAL, wx.NORMAL, False,
                                     u''))

        self.staticText1 = wx.StaticText(id=wxID_PANEL2STATICTEXT1, label=u'T:',
                                         name='staticText1', parent=self, pos=wx.Point(40, 88),
                                         size=wx.Size(17, 22), style=0)
        self.staticText1.SetFont(wx.Font(14, wx.SWISS, wx.NORMAL, wx.NORMAL,
                                         False, u'Arial'))

        self.textCtrl2 = wx.TextCtrl(id=wxID_PANEL2TEXTCTRL2, name='textCtrl2',
                                     parent=self, pos=wx.Point(48, 320), size=wx.Size(112, 216),
                                     style=wx.TE_MULTILINE, value=u'')
        self.textCtrl2.SetFont(wx.Font(14, wx.SWISS, wx.NORMAL, wx.NORMAL,
                                       False, u''))

        self.staticBox1 = wx.StaticBox(id=wxID_PANEL2STATICBOX1,
                                       label=u'Result:', name='staticBox1', parent=self, pos=wx.Point(32,
                                                                                                      272),
                                       size=wx.Size(568, 280), style=0)
        self.staticBox1.SetFont(wx.Font(12, wx.SWISS, wx.NORMAL, wx.NORMAL,
                                        False, u''))

        self.load_button = wx.Button(id=wxID_PANEL2LOAD_BUTTON, label=u'Load',
                                     name=u'load_button', parent=self, pos=wx.Point(432, 40),
                                     size=wx.Size(72, 26), style=0)
        self.load_button.SetFont(wx.Font(12, wx.SWISS, wx.NORMAL, wx.NORMAL,
                                         False, u'@Microsoft YaHei UI'))

        self.load_button.Bind(wx.EVT_BUTTON, self.loadtxt,
                              id=wxID_PANEL2LOAD_BUTTON)

        self.start_button = wx.Button(id=wxID_PANEL2START_BUTTON,
                                      label=u'Start', name=u'start_button', parent=self,
                                      pos=wx.Point(512, 40), size=wx.Size(72, 26), style=0)
        self.start_button.SetFont(wx.Font(12, wx.SWISS, wx.NORMAL, wx.NORMAL,
                                          False, u'Arial'))
        self.start_button.Bind(wx.EVT_BUTTON, self.start, id=wxID_PANEL2START_BUTTON)

        self.t_input = wx.TextCtrl(id=wxID_PANEL2T_INPUT, name=u't_input',
                                   parent=self, pos=wx.Point(168, 320), size=wx.Size(424, 216),
                                   style=wx.HSCROLL | wx.TE_MULTILINE, value=u'')
        self.t_input.SetFont(wx.Font(14, wx.SWISS, wx.NORMAL, wx.NORMAL, False,
                                     u''))

        self.staticText2 = wx.StaticText(id=wxID_PANEL2STATICTEXT2,
                                         label=u'FindList', name='staticText2', parent=self,
                                         pos=wx.Point(52, 299), size=wx.Size(56, 18), style=0)
        self.staticText2.SetFont(wx.Font(12, wx.SWISS, wx.NORMAL, wx.NORMAL,
                                         False, u''))

        self.textCtrl1 = wx.TextCtrl(id=wxID_PANEL2TEXTCTRL1, name='textCtrl1',
                                     parent=self, pos=wx.Point(80, 96), size=wx.Size(504, 160),
                                     style=wx.HSCROLL | wx.TE_MULTILINE, value=u'')
        self.textCtrl1.SetFont(wx.Font(14, wx.SWISS, wx.NORMAL, wx.NORMAL,
                                       False, u''))

        self.staticText3 = wx.StaticText(id=wxID_PANEL2STATICTEXT3,
                                         label=u'ShiftList', name='staticText3', parent=self,
                                         pos=wx.Point(168, 299), size=wx.Size(56, 18), style=0)
        self.staticText3.SetFont(wx.Font(12, wx.SWISS, wx.NORMAL, wx.NORMAL,
                                         False, u''))

    def loadtxt(self, evt):
        fs = open(ddir+"/s.txt")
        s = fs.read()
        self.s_input.SetValue(s)

        f = open(ddir+"/data.txt")
        ts = f.read()
        self.textCtrl1.SetValue(ts)
        # print(ts)
        pass

    def start(self, evt):
        import os
        os.popen(ddir+"/fa")
        f = open(ddir+"/file.txt")
        re = f.read()
        self.t_input.SetValue(re)
        ff = open(ddir+"/findlist.txt")
        ref = ff.read()
        self.textCtrl2.SetValue(ref)
        pass


class DemoFrame(wx.Frame):
    def __init__(self):
        wx.Frame.__init__(self, None, wx.ID_ANY, "Panel Tutorial")
        panel = Panel2(self)
        self.Show()


# ----------------------------------------------------------------------
if __name__ == "__main__":
    app = wx.PySimpleApp()
    frame = DemoFrame()
    app.MainLoop()
