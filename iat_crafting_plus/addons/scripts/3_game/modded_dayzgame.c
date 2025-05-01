modded class DayZGame
{
  protected ref IAT_TestWorkbenchRecipes m_TestWorkbenchRecipes;

  void DayZGame()
  {
    m_TestWorkbenchRecipes = new IAT_TestWorkbenchRecipes();
  }
  IAT_TestWorkbenchRecipes GetIATTestWorkbenchRecipes()
  {
    return m_TestWorkbenchRecipes;
  }
};