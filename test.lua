
-- local mytest = require "lua_add53"
--  mytest.ShowMsg();
--  print(mytest.sub2(1,2));
-- mylib = require("mylib")
-- mylib.printf("Say: %s\n", "hello world")
--求n的排列
-- package.path = "/home/magic/Lib/Lab/Dic/?.so";
local Dic=require "Dic"

Dic.init();
if Dic == nil then

    print("null");
end

Dic.add("Test",123);

print(math.ceil(Dic.get("Test")));





