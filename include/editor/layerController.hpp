#ifndef LAYERCONTROLLER_HPP
#define LAYERCONTROLLER_HPP

#include <memory>
#include <string>

class LayerManager;
class SelectionManager;
class TilesetManager;

namespace sfg
{
  class Table;
  class Desktop;
  class Entry;
  class Window;
}

class LayerController
{
public:
  LayerController(LayerManager &layerManager, SelectionManager &selectionManager, TilesetManager &tilesetManager, sfg::Desktop &desktop);
private:

  void changeActiveLayer(const std::string &name);

  void addLayer();
  void addLayerToTable(const std::string &name);

  void initGui();

  void initLayerWindow();
  void initNewLayerDialog();

private:
  LayerManager &mLayerManager;
  SelectionManager &mSelectionManager;
  TilesetManager &mTilesetManager;
  sfg::Desktop &mDesktop;

  struct
  {
    std::shared_ptr<sfg::Table> layerTable;
    unsigned tableRowCount;

    std::shared_ptr<sfg::Window> newLayerDialog;
    std::shared_ptr<sfg::Entry> newLayerName;
    std::shared_ptr<sfg::Entry> newLayerTileSizeX;
    std::shared_ptr<sfg::Entry> newLayerTileSizeY;
  }mGui;
};

#endif