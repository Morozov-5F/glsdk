newoption
{
   trigger     = "boost-dir",
   description = "Full path to the directory for the Boost distribution."
}

local internalBoostLoc = os.getcwd() .. "/boost"

if(not BoostDir) then
	function BoostDir()
		print(_OPTIONS["boost-dir"] or internalBoostLoc)
		return _OPTIONS["boost-dir"] or internalBoostLoc
	end
end