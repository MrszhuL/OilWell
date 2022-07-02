HPM_FILE_NAME="gn.tar"
HPM_TOOLS_LINUX_DOWNLOAD_URL="https://repo.huaweicloud.com/harmonyos/compiler/gn/1523/linux/gn.1523.tar"
HPM_TOOLS_WINDOWS_DOWNLOAD_URL=""
HPM_TOOLS_DOWNLOAD_URL=${HPM_TOOLS_WINDOWS_DOWNLOAD_URL}


if [ "$(uname)" = "Darwin" ]; then
    HPM_TOOLS_DOWNLOAD_URL=${HPM_TOOLS_LINUX_DOWNLOAD_URL}
elif [ "$(uname)" = "Linux" ]; then
    HPM_TOOLS_DOWNLOAD_URL=${HPM_TOOLS_LINUX_DOWNLOAD_URL}
fi

if [ ! ${HPM_GN_INSTALL} ]; then
    HPM_GN_INSTALL=${globalRepo}
fi

# HPM_TOOLS_DOWNLOAD_URL 镜像上的包下载地址  HPM_FILE_NAME 下载文件名称
curl ${HPM_TOOLS_DOWNLOAD_URL} -o ${HPM_FILE_NAME} 

# HPM_GN_INSTALL 用户可在hpmrc中配置的 gn安装地址 调用 卸载都依赖于该值
mkdir -p ${HPM_GN_INSTALL} 

# 解压工具包到用户指定位置
tar -xvf ${HPM_FILE_NAME} -C ${HPM_GN_INSTALL}
# 重试以防link文件首次找不到源文件
tar -xvf ${HPM_FILE_NAME} -C ${HPM_GN_INSTALL}

echo  "gn : ${HPM_GN_INSTALL}"
hpm config set HPM_GN_INSTALL ${HPM_GN_INSTALL}
