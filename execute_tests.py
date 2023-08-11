import Build.CToolKit as ct


test = ct.FolderTestPreset(folder='tests/')
test.generate_ouptut()
test.start_test()