--
-- version message
--

-- returned module
local version = {}

-- public
version.sent = false

-- private
local LEVEL1 = "&"
local LEVEL2 = "@"
local LEVEL3 = "#"
local LEVEL4 = "%"
local LEVEL5 = "^"

-- private
local VERSION_MESSAGE_TYPE = "V"
local PROTOCOL_VERSION = "0.1.0"

-- public
function version.get()
  local ver = {}
  -- [0] VERSION MESSAGE
  table.insert(ver, VERSION_MESSAGE_TYPE)
  -- [1] PROTOCOL VERSION
  table.insert(ver, PROTOCOL_VERSION)
  -- return version
  return table.concat(ver, LEVEL1)
end

return version
