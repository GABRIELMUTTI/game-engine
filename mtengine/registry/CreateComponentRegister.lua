json = require "registry/json"

local function read_all(filename)
   local file = assert(io.open(filename, "rb"))
   local content = file:read("*all")
   file:close()
   
   return content
end

local function get_register_line(component_name)
   return "factory->registerType<" .. component_name .. ">(\"" .. component_name .. "\");\n"
end

local function get_include_line(component_name)
   return "#include \"mtengine/component/" .. component_name .. ".hpp\"\n"
end

local function create_register_file(component_info)
   local filename = component_info.register_source_output
   local file = assert(io.open(filename, "w"))

   file:write("#include \"mtengine/factory/IRegister.hpp\"\n")
   
   for i = 1, #component_info.components do
      file:write(get_include_line(component_info.components[i]))
   end
   
   file:write(
      [[
        namespace mtengine
        {
            class ComponentRegister : public IRegister<Component>
            {
                public:
                    ComponentRegister()
                    {

                    }

                    void registerTypes(Factory<Component>* factory)
                    {
]])

   for i = 1, #component_info.components do
      file:write(get_register_line(component_info.components[i]))
   end

   file:write("}};}")
   file:close()
end

local content = read_all("registry/component_registry.json")

local jsonDecoded = json.decode(content)

create_register_file(jsonDecoded)
