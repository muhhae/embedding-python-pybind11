import App

def Update(Pet):
    print("Update")
    Pet.setName("Doni")
    Pet.setAge(10)
    
def PopulatePetStore(PetStore):
    PetStore.addPet(App.Pet("Dog"))
    PetStore.addPet(App.Pet("Cat"))
    PetStore.addPet(App.Pet("Fox"))
    PetStore.addPet(App.Pet("Bear"))
    
class Populator:
    def __init__(self, PetStore):
        self.PetStore = PetStore
    def populate(self):
        self.PetStore.addPet(App.Pet("Tono"))
        self.PetStore.addPet(App.Pet("Budi"))
        self.PetStore.addPet(App.Pet("Toti"))
        self.PetStore.addPet(App.Pet("Tutu"))