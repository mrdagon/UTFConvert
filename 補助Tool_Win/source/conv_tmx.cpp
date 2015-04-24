#include <SDXFrameWork.h>
#include <Multimedia/SDXafx.h>

#include <Tiled/TmxToCode.h>

int main(int argc, char *argv[])
{
	//設定を読み込む
	SDX::File file("tiled/config.txt", SDX::FileMode::Read);
	auto strS = file.GetCsvToString2();
	file.Close();
	std::string tmxfile;
	std::string tClass;
	std::string tScene;
	std::string tEnum;
	std::string prefix;
	std::string nSpace;

	for (auto &str : strS)
	{
		if (str[0] == "tmxfile")
		{
			tmxfile = str[1];
		}
		else if (str[0] == "class")
		{
			tClass += str[1];
		}
		else if(str[0] == "scene")
		{
			tScene += str[1];
		}
		else if(str[0] == "enum")
		{
			tEnum += str[1];
		}
		else if(str[0] == "prefix")
		{
			prefix = str[1];
		}
		else if (str[0] == "namespace")
		{
			nSpace = str[1];
		}
	}


	//1つ目は実行ファイルのパス、以下ドロップしたファイル
	if ( argv[1] != nullptr)
	{
		//ファイル名を変更
		tmxfile = argv[1];
		file.Open("tiled/config_tiled.txt", SDX::FileMode::Write);
		file.AddLine({ "tmxfile," , tmxfile});
		file.AddLine({ "class,", tClass });
		file.AddLine({ "scene,", tScene });
		file.AddLine({ "enum,", tEnum });
		file.AddLine({ "prefix,", prefix });
		file.AddLine({ "namespace,", nSpace });
		file.Close();
	}
	
	SDX::TMXtoCode(tmxfile.c_str(), tClass.c_str() , tScene.c_str() , tEnum.c_str() , prefix.c_str() ,nSpace.c_str() );

	return 0;
}