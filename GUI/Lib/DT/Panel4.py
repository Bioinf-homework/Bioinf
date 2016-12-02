#Boa:FramePanel:Panel3

import wx

import os

ddir = os.path.split(os.path.realpath(__file__))[0]


class Panel4(wx.Panel):
    def __init__(self, prnt):
        # generated method, don't edit
        wx.Panel.__init__(self, name='', parent=prnt,
              pos=wx.Point(415, 167), size=wx.Size(526, 475),
              style=wx.TAB_TRAVERSAL)
        self.SetClientSize(wx.Size(510, 436))


        self.start_button = wx.Button(label=u'Start', name=u'start_button', parent=self,
              pos=wx.Point(300, 100), size=wx.Size(75, 24), style=0)

        self.start_button.Bind(wx.EVT_BUTTON, self.start)
        self.textCtrl1 = wx.TextCtrl(name='textCtrl1',
                                     parent=self, pos=wx.Point(100, 200), size=wx.Size(504, 160),
                                     style=wx.TE_MULTILINE, value=u'')
        self.textCtrl1.SetFont(wx.Font(14, wx.SWISS, wx.NORMAL, wx.NORMAL,
                                       False, u''))

        self.draw_button = wx.Button(label=u'Draw', name=u'draw_button', parent=self,
              pos=wx.Point(300, 150), size=wx.Size(75, 24), style=0)

        self.draw_button.Bind(wx.EVT_BUTTON, self.draw)

    def start(self ,evt):
        if __name__ != "__main__":
            os.chdir("Lib/DT")
        os.popen(ddir+"/DT")
        with open(ddir+"/re.txt") as f:
            self.textCtrl1.SetValue(f.read())

    def draw(self, evt):
        import drawtree
        drawtree.run()



class DemoFrame(wx.Frame):
    def __init__(self):
        wx.Frame.__init__(self, None, wx.ID_ANY, "Panel Tutorial")
        panel = Panel4(self)
        self.Show()
        
#----------------------------------------------------------------------
if __name__ == "__main__":
    app = wx.PySimpleApp()
    frame = DemoFrame()
    app.MainLoop()