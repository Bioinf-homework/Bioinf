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
              pos=wx.Point(300, 300), size=wx.Size(75, 24), style=0)

        self.start_button.Bind(wx.EVT_BUTTON, self.start)
    def start(self ,evt):
        import drawtree
        import json
        with open(ddir+"/re.json") as f:
            data = json.load(f)
            drawtree.createPlot(data)




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