json = require "registry/json"

local function read_all(filename)
   local file = assert(io.open(filename, "rb"))
   local content = file:read("*all")
   file:close()
   
   return content
end

local function get_register_line(system_name)
   return "factory->registerType<" .. system_name .. ">(\"" .. system_name .. "\");\n"
end

local function get_include_line(system_name)
   return "#include \"mtengine/system/" .. system_name .. ".hpp\"\n"
end

local function create_register_file(system_info)
   local filename = system_info.register_source_output
   local file = assert(io.open(filename, "w"))

   file:write("#include \"mtengine/factory/IRegister.hpp\"\n")
   
   for i = 1, #system_info.systems do
      file:write(get_include_line(system_info.systems[i]))
   end
   
   file:write(
      [[
        namespace mtengine
        {
            class SystemRegister : public IRegister<System, int>
            {
                public:
                    SystemRegister()
                    {

                    }

                    void registerTypes(Factory<System, int>* factory)
                    {
]])

   for i = 1, #system_info.systems do
      file:write(get_register_line(system_info.systems[i]))
   end

   file:write("}};}")
   file:close()
end

local content = read_all("registry/system_registry.json")

local jsonDecoded = json.decode(content)

create_register_file(jsonDecoded)
