#Boa:FramePanel:Panel1

import wx

[wxID_PANEL1, wxID_PANEL1DATATEXT, wxID_PANEL1DATA_INPUT, wxID_PANEL1INTRO, 
 wxID_PANEL1ITEXT, wxID_PANEL1I_INPUT, wxID_PANEL1JTEXT, wxID_PANEL1J_INPUT, 
 wxID_PANEL1LOAD_BTN, wxID_PANEL1RESULTBOX, wxID_PANEL1START_BTN, wxID_PANEL1RESULT,
 ] = [wx.NewId() for _init_ctrls in range(12)]

class Panel1(wx.Panel):
    def __init__(self, prnt):
        # generated method, don't edit
        wx.Panel.__init__(self, id=wxID_PANEL1, name='', parent=prnt,
              pos=wx.Point(453, 277), size=wx.Size(387, 400),
              style=wx.TAB_TRAVERSAL)
        self.SetClientSize(wx.Size(371, 361))

        self.dataText = wx.StaticText(id=wxID_PANEL1DATATEXT, label=u'data',
              name=u'dataText', parent=self, pos=wx.Point(56, 56),
              size=wx.Size(24, 14), style=0)
        self.dataText.Enable(True)

        self.iText = wx.StaticText(id=wxID_PANEL1ITEXT, label=u'I',
              name=u'iText', parent=self, pos=wx.Point(56, 96), size=wx.Size(32,
              14), style=0)

        self.data_input = wx.TextCtrl(id=wxID_PANEL1DATA_INPUT,
              name=u'data_input', parent=self, pos=wx.Point(112, 56),
              size=wx.Size(100, 22), style=0, value=u'')

        self.i_input = wx.TextCtrl(id=wxID_PANEL1I_INPUT, name=u'i_input',
              parent=self, pos=wx.Point(112, 96), size=wx.Size(100, 22),
              style=0, value=u'')

        self.jText = wx.StaticText(id=wxID_PANEL1JTEXT, label=u'J',
              name=u'jText', parent=self, pos=wx.Point(56, 136),
              size=wx.Size(24, 14), style=0)

        self.j_input = wx.TextCtrl(id=wxID_PANEL1J_INPUT, name=u'j_input',
              parent=self, pos=wx.Point(112, 136), size=wx.Size(100, 22),
              style=0, value=u'')

        self.load_btn = wx.Button(id=wxID_PANEL1LOAD_BTN, label=u'Load',
              name=u'load_btn', parent=self, pos=wx.Point(232, 56),
              size=wx.Size(75, 24), style=0)
        self.load_btn.Bind(wx.EVT_BUTTON, self.OnLoad_btnButton,
              id=wxID_PANEL1LOAD_BTN)

        self.start_btn = wx.Button(id=wxID_PANEL1START_BTN, label=u'Start',
              name=u'start_btn', parent=self, pos=wx.Point(232, 136),
              size=wx.Size(75, 24), style=0)
        self.start_btn.Bind(wx.EVT_BUTTON, self.OnStart_btnButton,
              id=wxID_PANEL1START_BTN)

        self.ResultBox = wx.StaticBox(id=wxID_PANEL1RESULTBOX, label=u'Result:',
              name=u'ResultBox', parent=self, pos=wx.Point(56, 208),
              size=wx.Size(248, 128), style=0)

        self.intro = wx.StaticText(id=wxID_PANEL1INTRO,
              label=u'\u5b9e\u9a8c\u8bf4\u660e\uff1alabalaba', name=u'intro',
              parent=self, pos=wx.Point(56, 176), size=wx.Size(102, 14),
              style=0)
        self.result = wx.TextCtrl(id=wxID_PANEL1RESULT, name=u'result',
              parent=self, pos=wx.Point(64, 224), size=wx.Size(232, 104),
              style=wx.TE_MULTILINE, value=u'')
        self.result.SetEditable(False)
        
    # def __init__(self, parent, id, pos, size, style, name):
        # self._init_ctrls(parent)

    def OnStart_btnButton(self, event):
        # print('ss')
        i = self.i_input.GetValue()
        j = self.j_input.GetValue()
        if i == "":
          i = "-1"
        if j == "":
          j = "-1"
        # print(i)
        # print(j)
        import ctypes
        so = ctypes.cdll.LoadLibrary
        lib = so("./libk.so")

        rst = lib.test(int(i),int(j))

        # print(rst)
        size = -1
        rst = ctypes.string_at(rst, size)
        # print(rst.decode('utf-8'))
        self.result.SetValue(rst)


    def OnLoad_btnButton(self, event):
        f = open("data.txt","r")
        x = f.readline()
        self.data_input.SetValue(x)

class DemoFrame(wx.Frame):
    def __init__(self):
        wx.Frame.__init__(self, None, wx.ID_ANY, "Panel Tutorial")
        panel = Panel1(self)
        self.Show()
        
#----------------------------------------------------------------------
if __name__ == "__main__":
    app = wx.PySimpleApp()
    frame = DemoFrame()
    app.MainLoop()