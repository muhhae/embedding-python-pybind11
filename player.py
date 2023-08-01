import App

class PlayerController:
    def __init__(self, game):
        self.game = game
        print("PlayerController.__init__")
        print("Game: ", game)
    def OnCreate(self):
        pass
    def OnUpdate(self):
        print("PlayerController.OnUpdate")
        Player = self.game.getEntity("Player")
        print("Player: ", Player)
        C = Player.addColor(App.Color())
        print ("C: ", C)
        T = Player.addTransform(App.Transform())
        print ("T: ", T)