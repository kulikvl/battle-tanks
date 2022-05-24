#SDL2_TowerDefense Makefile

PROGRAM = towerdefense

CXX = g++ -std=c++17 -F /Library/Frameworks
CXXFLAGS = -w

LD = g++ -std=c++17
LDFLAGS =  -framework SDL2 -F /Library/Frameworks/ -I /Library/Frameworks/SDL2.framework/Headers -w    -framework SDL2_image -F /Library/Frameworks/ -I /Library/Frameworks/SDL2_image.framework/Headers 

all: $(PROGRAM)

# run: compile 
# 	./$(PROGRAM) 

# compile: $(PROGRAM)

# doc: src/main.hpp src/game.hpp ...
# 	doxygen Doxyfile

$(PROGRAM):  Button.o ButtonManager.o Coin.o Color.o Config.o DamageableObject.o Firebird.o Freeze.o Game.o GameObject.o Heart.o HeavyTank.o LightTank.o Log.o MazeSolver.o MediumTank.o MoveableObject.o ParticleEffect.o ParticleFire.o ParticleFreeze.o ParticleShotExplosion.o ParticleShotSmoke.o ParticleSystem.o ParticleTankExplosion.o Player.o ShootableObject.o Smoky.o Sprite.o TabManager.o Tank.o TankManager.o Tile.o TileManager.o TileTurret.o Timer.o TimerCounter.o Turret.o TurretManager.o Utils.o Window.o SDL.o main.o
	$(LD) $(LDFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(PROGRAM) *.o 


SDL.o: SDL.hpp Log.hpp
Button.o: Button.cpp Button.hpp SDL.hpp
ButtonManager.o: ButtonManager.cpp ButtonManager.hpp Button.hpp SDL.hpp
Coin.o: Coin.cpp Window.hpp SDL.hpp
Color.o: Color.cpp Color.hpp Utils.hpp
Config.o: Config.cpp Config.hpp Utils.hpp Log.hpp
DamageableObject.o: DamageableObject.cpp DamageableObject.hpp Log.hpp
Firebird.o: Firebird.cpp Firebird.hpp Turret.hpp GameObject.hpp SDL.hpp
Freeze.o: Freeze.cpp Freeze.hpp Turret.hpp GameObject.hpp SDL.hpp
Game.o: Game.cpp Game.hpp Window.hpp SDL.hpp
GameObject.o: GameObject.cpp GameObject.hpp SDL.hpp
Heart.o: Heart.cpp Window.hpp SDL.hpp
HeavyTank.o: HeavyTank.cpp HeavyTank.hpp Tank.hpp GameObject.hpp SDL.hpp
LightTank.o: LightTank.cpp LightTank.hpp Tank.hpp GameObject.hpp SDL.hpp
Log.o: Log.cpp Log.hpp
MazeSolver.o: MazeSolver.cpp MazeSolver.hpp Tile.hpp Window.hpp SDL.hpp 
MediumTank.o: MediumTank.cpp MediumTank.hpp Tank.hpp GameObject.hpp
MoveableObject.o: MoveableObject.cpp MoveableObject.hpp
ParticleEffect.o: ParticleEffect.cpp ParticleEffect.hpp
ParticleFire.o: ParticleFire.cpp ParticleEffect.hpp ParticleSystem.hpp
ParticleFreeze.o: ParticleFreeze.cpp ParticleEffect.hpp
ParticleShotExplosion.o: ParticleShotExplosion.cpp ParticleEffect.hpp
ParticleShotSmoke.o: ParticleShotSmoke.cpp ParticleEffect.hpp
ParticleSystem.o: ParticleSystem.cpp ParticleSystem.hpp
ParticleTankExplosion.o: ParticleTankExplosion.cpp ParticleEffect.hpp
Player.o: Player.cpp Player.hpp
ShootableObject.o: ShootableObject.cpp ShootableObject.hpp
Smoky.o: Smoky.cpp Smoky.hpp Turret.hpp GameObject.hpp SDL.hpp
Sprite.o: Sprite.cpp Sprite.hpp SDL.hpp
TabManager.o: TabManager.cpp TabManager.hpp Window.hpp SDL.hpp
Tank.o: Tank.cpp Tank.hpp GameObject.hpp SDL.hpp
TankManager.o: TankManager.cpp TankManager.hpp Window.hpp SDL.hpp
Tile.o: Tile.cpp Tile.hpp Window.hpp SDL.hpp
TileManager.o: TileManager.cpp TileManager.hpp Tile.hpp Window.hpp
TileTurret.o: TileTurret.cpp TileTurret.hpp Tile.hpp Window.hpp SDL.hpp
Timer.o: Timer.cpp Timer.hpp SDL.hpp
TimerCounter.o: TimerCounter.cpp TimerCounter.hpp Timer.hpp
Turret.o: Turret.cpp Turret.hpp GameObject.hpp SDL.hpp
TurretManager.o: TurretManager.cpp TurretManager.hpp Turret.hpp
Utils.o: Utils.cpp Utils.hpp
Window.o: Window.cpp Window.hpp SDL.hpp

main.o: main.cpp SDL.hpp Log.hpp Window.hpp Game.hpp Config.hpp
